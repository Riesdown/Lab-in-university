// Generated by gencpp from file nlink_parser/TofsenseMFrame0Pixel.msg
// DO NOT EDIT!


#ifndef NLINK_PARSER_MESSAGE_TOFSENSEMFRAME0PIXEL_H
#define NLINK_PARSER_MESSAGE_TOFSENSEMFRAME0PIXEL_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace nlink_parser
{
template <class ContainerAllocator>
struct TofsenseMFrame0Pixel_
{
  typedef TofsenseMFrame0Pixel_<ContainerAllocator> Type;

  TofsenseMFrame0Pixel_()
    : dis(0.0)
    , dis_status(0)
    , signal_strength(0)  {
    }
  TofsenseMFrame0Pixel_(const ContainerAllocator& _alloc)
    : dis(0.0)
    , dis_status(0)
    , signal_strength(0)  {
  (void)_alloc;
    }



   typedef float _dis_type;
  _dis_type dis;

   typedef uint8_t _dis_status_type;
  _dis_status_type dis_status;

   typedef uint16_t _signal_strength_type;
  _signal_strength_type signal_strength;





  typedef boost::shared_ptr< ::nlink_parser::TofsenseMFrame0Pixel_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::nlink_parser::TofsenseMFrame0Pixel_<ContainerAllocator> const> ConstPtr;

}; // struct TofsenseMFrame0Pixel_

typedef ::nlink_parser::TofsenseMFrame0Pixel_<std::allocator<void> > TofsenseMFrame0Pixel;

typedef boost::shared_ptr< ::nlink_parser::TofsenseMFrame0Pixel > TofsenseMFrame0PixelPtr;
typedef boost::shared_ptr< ::nlink_parser::TofsenseMFrame0Pixel const> TofsenseMFrame0PixelConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::nlink_parser::TofsenseMFrame0Pixel_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::nlink_parser::TofsenseMFrame0Pixel_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::nlink_parser::TofsenseMFrame0Pixel_<ContainerAllocator1> & lhs, const ::nlink_parser::TofsenseMFrame0Pixel_<ContainerAllocator2> & rhs)
{
  return lhs.dis == rhs.dis &&
    lhs.dis_status == rhs.dis_status &&
    lhs.signal_strength == rhs.signal_strength;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::nlink_parser::TofsenseMFrame0Pixel_<ContainerAllocator1> & lhs, const ::nlink_parser::TofsenseMFrame0Pixel_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace nlink_parser

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::nlink_parser::TofsenseMFrame0Pixel_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::nlink_parser::TofsenseMFrame0Pixel_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::nlink_parser::TofsenseMFrame0Pixel_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::nlink_parser::TofsenseMFrame0Pixel_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::nlink_parser::TofsenseMFrame0Pixel_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::nlink_parser::TofsenseMFrame0Pixel_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::nlink_parser::TofsenseMFrame0Pixel_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d8d02fd7942fc6660671b1c9411abd9c";
  }

  static const char* value(const ::nlink_parser::TofsenseMFrame0Pixel_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd8d02fd7942fc666ULL;
  static const uint64_t static_value2 = 0x0671b1c9411abd9cULL;
};

template<class ContainerAllocator>
struct DataType< ::nlink_parser::TofsenseMFrame0Pixel_<ContainerAllocator> >
{
  static const char* value()
  {
    return "nlink_parser/TofsenseMFrame0Pixel";
  }

  static const char* value(const ::nlink_parser::TofsenseMFrame0Pixel_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::nlink_parser::TofsenseMFrame0Pixel_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32 dis\n"
"uint8 dis_status\n"
"uint16 signal_strength\n"
;
  }

  static const char* value(const ::nlink_parser::TofsenseMFrame0Pixel_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::nlink_parser::TofsenseMFrame0Pixel_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.dis);
      stream.next(m.dis_status);
      stream.next(m.signal_strength);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct TofsenseMFrame0Pixel_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::nlink_parser::TofsenseMFrame0Pixel_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::nlink_parser::TofsenseMFrame0Pixel_<ContainerAllocator>& v)
  {
    s << indent << "dis: ";
    Printer<float>::stream(s, indent + "  ", v.dis);
    s << indent << "dis_status: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.dis_status);
    s << indent << "signal_strength: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.signal_strength);
  }
};

} // namespace message_operations
} // namespace ros

#endif // NLINK_PARSER_MESSAGE_TOFSENSEMFRAME0PIXEL_H