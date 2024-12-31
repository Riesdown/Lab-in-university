import csv
import json

class CSV:
    def __init__(self, file_name):
        self.file = open(file_name, mode='a')  
        self.writer = csv.writer(self.file)
        
    def Save_Label(self, label):
        self.writer.writerow(label)
        
    def Save_Data(self, data):
        self.writer.writerow(data)
        
    def Trans_JsonData(self, data):
        return json.dumps(data)
        
    def Get_JsonData(self, data):
        return json.loads(data)