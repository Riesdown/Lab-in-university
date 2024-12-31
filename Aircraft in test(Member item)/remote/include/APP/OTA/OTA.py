import os
import time
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.firefox.service import Service as FirefoxService
from selenium.webdriver.firefox.options import Options as FirefoxOptions
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC

'''..............................................打开浏览器..................................................................................................'''

# 设置 Firefox 浏览器的选项
firefox_options = FirefoxOptions()

# 无图形界面
firefox_options.add_argument('--headless')  # 启用无头模式

firefox_binary = r'E:\火绒\firefox.exe'  
firefox_options.binary_location = firefox_binary

driver_path = r'E:\浏览器驱动\geckodriver.exe' 

print("\n正在启动Firefox浏览器...")
driver = webdriver.Firefox(service=FirefoxService(executable_path=driver_path), options=firefox_options)
print("\nFirefox浏览器启动成功")


'''..............................................获取bin文件路径..................................................................................................'''

# 回退
def backtrack_path(path, levels):
    for _ in range(levels):
        path = os.path.dirname(path)
    return path

# 当前文件的目录
current_directory = os.path.dirname(__file__)

# 回退
base_directory = backtrack_path(current_directory, 3)

# 构建目标文件路径
file_path = os.path.join(base_directory, ".pio", "build", "alksesp32", "firmware.bin")

print("\n文件路径:", file_path)

'''..............................................登录网站..................................................................................................'''
upload_button = 0

# 访问目标网页
url = 'http://192.168.137.137/update'

while True:
    driver.execute_script(f"window.location = '{url}'")
    
    try:
        elegant_ota_img = WebDriverWait(driver, 10).until(
            EC.presence_of_element_located((By.XPATH, '//img[@alt="ElegantOTA"]'))
        )
        if elegant_ota_img:
            print("\n网站登录成功!!!")
            print("\n等待网站加载完毕...")
            break
    except:
        print("等待img元素超时，重新加载页面...")
        continue
    
while True:
    try:
        # 使用显式等待，等待input[type="file"]元素加载完成，超时时间为10秒
        upload_button = WebDriverWait(driver, 10).until(
            EC.presence_of_element_located((By.XPATH, '//input[@type="file"]'))
        )
        if upload_button:
            print("\n上传按钮加载完成")
            break
    except:
        print("等待文件上传按钮超时，重新尝试...")
        continue

'''..............................................文件上传，按下按键上传..................................................................................................'''
# JavaScript 找文本，上面的也行
progress_script = """
return document.querySelector('div.pt-2').textContent.trim();
"""


send_flag = 0

# 进度条函数
def print_progress_bar(percent):
    bar_length = 50 
    block = int(round(bar_length * percent / 100))
    progress_bar = '=' * block + ' ' * (bar_length - block)
    print(f'\r[{progress_bar}] {percent:.1f}%', end='', flush=True)



while True:
    if send_flag == 0:
        user_input = input("输入q回车上传文件:").strip().lower()
        if user_input == 'q':
            print("\n开始上传文件...")
            send_flag = 1
            continue
    if send_flag == 1:
        upload_button = driver.find_element(By.XPATH, '//input[@type="file"]')
        upload_button.send_keys(file_path)
        while True:
            progress_text = driver.execute_script(progress_script)
            
            try:
                progress_value = int(progress_text.strip('%'))
            except ValueError:
                progress_value = 0
            
            
            print_progress_bar(progress_value)

            # 检查是否存在back按钮
            try:
                back_button = driver.find_element(By.CLASS_NAME, 'btn.btn-primary.mt-3')
                if back_button:
                    print_progress_bar(100)
                    print("\n上传完成!\n")
                    send_flag = 0
                    back_button.click()
                    break
            except:
                pass

            try:
                back_button2 = driver.find_element(By.CLASS_NAME, 'btn.btn-primary.ml-2')
                if back_button2:
                    print("\n网络错误!")
                    break
            except:
                pass

            time.sleep(0.1)

