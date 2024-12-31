// Generated by gencpp from file user_messages/navigation_ctrl.msg
// DO NOT EDIT!


#ifndef USER_MESSAGES_MESSAGE_NAVIGATION_CTRL_H
#define USER_MESSAGES_MESSAGE_NAVIGATION_CTRL_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace user_messages
{
template <class ContainerAllocator>
struct navigation_ctrl_
{
  typedef navigation_ctrl_<ContainerAllocator> Type;

  navigation_ctrl_()
    : x(0.0)
    , y(0.0)
    , z(0.0)
    , nav_mode(0)
    , frame_id(0)
    , num(0)
    , execution_time(0)
    , update_flag(0)  {
    }
  navigation_ctrl_(const ContainerAllocator& _alloc)
    : x(0.0)
    , y(0.0)
    , z(0.0)
    , nav_mode(0)
    , frame_id(0)
    , num(0)
    , execution_time(0)
    , update_flag(0)  {
  (void)_alloc;
    }



   typedef float _x_type;
  _x_type x;

   typedef float _y_type;
  _y_type y;

   typedef float _z_type;
  _z_type z;

   typedef uint8_t _nav_mode_type;
  _nav_mode_type nav_mode;

   typedef uint8_t _frame_id_type;
  _frame_id_type frame_id;

   typedef uint16_t _num_type;
  _num_type num;

   typedef uint32_t _execution_time_type;
  _execution_time_type execution_time;

   typedef uint8_t _update_flag_type;
  _update_flag_type update_flag;



// reducing the odds to have name collisions with Windows.h 
#if defined(_WIN32) && defined(BODY_FRAME)
  #undef BODY_FRAME
#endif
#if defined(_WIN32) && defined(MAP_FRAME)
  #undef MAP_FRAME
#endif
#if defined(_WIN32) && defined(RELATIVE_MODE)
  #undef RELATIVE_MODE
#endif
#if defined(_WIN32) && defined(GLOBAL_MODE)
  #undef GLOBAL_MODE
#endif
#if defined(_WIN32) && defined(CMD_VEL_MODE)
  #undef CMD_VEL_MODE
#endif

  enum {
    BODY_FRAME = 0u,
    MAP_FRAME = 1u,
    RELATIVE_MODE = 0u,
    GLOBAL_MODE = 1u,
    CMD_VEL_MODE = 2u,
  };


  typedef boost::shared_ptr< ::user_messages::navigation_ctrl_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::user_messages::navigation_ctrl_<ContainerAllocator> const> ConstPtr;

}; // struct navigation_ctrl_

typedef ::user_messages::navigation_ctrl_<std::allocator<void> > navigation_ctrl;

typedef boost::shared_ptr< ::user_messages::navigation_ctrl > navigation_ctrlPtr;
typedef boost::shared_ptr< ::user_messages::navigation_ctrl const> navigation_ctrlConstPtr;

// constants requiring out of line definition

   

   

   

   

   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::user_messages::navigation_ctrl_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::user_messages::navigation_ctrl_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::user_messages::navigation_ctrl_<ContainerAllocator1> & lhs, const ::user_messages::navigation_ctrl_<ContainerAllocator2> & rhs)
{
  return lhs.x == rhs.x &&
    lhs.y == rhs.y &&
    lhs.z == rhs.z &&
    lhs.nav_mode == rhs.nav_mode &&
    lhs.frame_id == rhs.frame_id &&
    lhs.num == rhs.num &&
    lhs.execution_time == rhs.execution_time &&
    lhs.update_flag == rhs.update_flag;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::user_messages::navigation_ctrl_<ContainerAllocator1> & lhs, const ::user_messages::navigation_ctrl_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace user_messages

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::user_messages::navigation_ctrl_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::user_messages::navigation_ctrl_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::user_messages::navigation_ctrl_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::user_messages::navigation_ctrl_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::user_messages::navigation_ctrl_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::user_messages::navigation_ctrl_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::user_messages::navigation_ctrl_<ContainerAllocator> >
{
  static const char* value()
  {
    return "57540d12dfd9892331224880fa18114a";
  }

  static const char* value(const ::user_messages::navigation_ctrl_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x57540d12dfd98923ULL;
  static const uint64_t static_value2 = 0x31224880fa18114aULL;
};

template<class ContainerAllocator>
struct DataType< ::user_messages::navigation_ctrl_<ContainerAllocator> >
{
  static const char* value()
  {
    return "user_messages/navigation_ctrl";
  }

  static const char* value(const ::user_messages::navigation_ctrl_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::user_messages::navigation_ctrl_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32 x\n"
"float32 y\n"
"float32 z\n"
"uint8 nav_mode\n"
"uint8 frame_id\n"
"uint16 num\n"
"uint32 execution_time\n"
"uint8 update_flag\n"
"\n"
"uint8 BODY_FRAME=0\n"
"uint8 MAP_FRAME=1\n"
"uint8 RELATIVE_MODE=0\n"
"uint8 GLOBAL_MODE=1\n"
"uint8 CMD_VEL_MODE=2\n"
;
  }

  static const char* value(const ::user_messages::navigation_ctrl_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::user_messages::navigation_ctrl_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.x);
      stream.next(m.y);
      stream.next(m.z);
      stream.next(m.nav_mode);
      stream.next(m.frame_id);
      stream.next(m.num);
      stream.next(m.execution_time);
      stream.next(m.update_flag);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct navigation_ctrl_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::user_messages::navigation_ctrl_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::user_messages::navigation_ctrl_<ContainerAllocator>& v)
  {
    s << indent << "x: ";
    Printer<float>::stream(s, indent + "  ", v.x);
    s << indent << "y: ";
    Printer<float>::stream(s, indent + "  ", v.y);
    s << indent << "z: ";
    Printer<float>::stream(s, indent + "  ", v.z);
    s << indent << "nav_mode: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.nav_mode);
    s << indent << "frame_id: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.frame_id);
    s << indent << "num: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.num);
    s << indent << "execution_time: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.execution_time);
    s << indent << "update_flag: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.update_flag);
  }
};

} // namespace message_operations
} // namespace ros

#endif // USER_MESSAGES_MESSAGE_NAVIGATION_CTRL_H
