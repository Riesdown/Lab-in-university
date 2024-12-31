// Generated by gencpp from file shijue_pkg/weizhi_data.msg
// DO NOT EDIT!


#ifndef SHIJUE_PKG_MESSAGE_WEIZHI_DATA_H
#define SHIJUE_PKG_MESSAGE_WEIZHI_DATA_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace shijue_pkg
{
template <class ContainerAllocator>
struct weizhi_data_
{
  typedef weizhi_data_<ContainerAllocator> Type;

  weizhi_data_()
    : wz_x(0.0)
    , wz_y(0.0)
    , flag(false)  {
    }
  weizhi_data_(const ContainerAllocator& _alloc)
    : wz_x(0.0)
    , wz_y(0.0)
    , flag(false)  {
  (void)_alloc;
    }



   typedef float _wz_x_type;
  _wz_x_type wz_x;

   typedef float _wz_y_type;
  _wz_y_type wz_y;

   typedef uint8_t _flag_type;
  _flag_type flag;





  typedef boost::shared_ptr< ::shijue_pkg::weizhi_data_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::shijue_pkg::weizhi_data_<ContainerAllocator> const> ConstPtr;

}; // struct weizhi_data_

typedef ::shijue_pkg::weizhi_data_<std::allocator<void> > weizhi_data;

typedef boost::shared_ptr< ::shijue_pkg::weizhi_data > weizhi_dataPtr;
typedef boost::shared_ptr< ::shijue_pkg::weizhi_data const> weizhi_dataConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::shijue_pkg::weizhi_data_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::shijue_pkg::weizhi_data_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::shijue_pkg::weizhi_data_<ContainerAllocator1> & lhs, const ::shijue_pkg::weizhi_data_<ContainerAllocator2> & rhs)
{
  return lhs.wz_x == rhs.wz_x &&
    lhs.wz_y == rhs.wz_y &&
    lhs.flag == rhs.flag;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::shijue_pkg::weizhi_data_<ContainerAllocator1> & lhs, const ::shijue_pkg::weizhi_data_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace shijue_pkg

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::shijue_pkg::weizhi_data_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::shijue_pkg::weizhi_data_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::shijue_pkg::weizhi_data_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::shijue_pkg::weizhi_data_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::shijue_pkg::weizhi_data_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::shijue_pkg::weizhi_data_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::shijue_pkg::weizhi_data_<ContainerAllocator> >
{
  static const char* value()
  {
    return "9352d5e7401b90403eb2ff4ec8292292";
  }

  static const char* value(const ::shijue_pkg::weizhi_data_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x9352d5e7401b9040ULL;
  static const uint64_t static_value2 = 0x3eb2ff4ec8292292ULL;
};

template<class ContainerAllocator>
struct DataType< ::shijue_pkg::weizhi_data_<ContainerAllocator> >
{
  static const char* value()
  {
    return "shijue_pkg/weizhi_data";
  }

  static const char* value(const ::shijue_pkg::weizhi_data_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::shijue_pkg::weizhi_data_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32 wz_x\n"
"float32 wz_y\n"
"bool flag\n"
;
  }

  static const char* value(const ::shijue_pkg::weizhi_data_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::shijue_pkg::weizhi_data_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.wz_x);
      stream.next(m.wz_y);
      stream.next(m.flag);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct weizhi_data_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::shijue_pkg::weizhi_data_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::shijue_pkg::weizhi_data_<ContainerAllocator>& v)
  {
    s << indent << "wz_x: ";
    Printer<float>::stream(s, indent + "  ", v.wz_x);
    s << indent << "wz_y: ";
    Printer<float>::stream(s, indent + "  ", v.wz_y);
    s << indent << "flag: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.flag);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SHIJUE_PKG_MESSAGE_WEIZHI_DATA_H
