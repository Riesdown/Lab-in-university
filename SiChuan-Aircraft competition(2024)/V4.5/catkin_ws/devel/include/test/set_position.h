// Generated by gencpp from file test/set_position.msg
// DO NOT EDIT!


#ifndef TEST_MESSAGE_SET_POSITION_H
#define TEST_MESSAGE_SET_POSITION_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace test
{
template <class ContainerAllocator>
struct set_position_
{
  typedef set_position_<ContainerAllocator> Type;

  set_position_()
    : x(0.0)
    , y(0.0)
    , z(0.0)
    , flag1(0.0)  {
    }
  set_position_(const ContainerAllocator& _alloc)
    : x(0.0)
    , y(0.0)
    , z(0.0)
    , flag1(0.0)  {
  (void)_alloc;
    }



   typedef float _x_type;
  _x_type x;

   typedef float _y_type;
  _y_type y;

   typedef float _z_type;
  _z_type z;

   typedef float _flag1_type;
  _flag1_type flag1;





  typedef boost::shared_ptr< ::test::set_position_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::test::set_position_<ContainerAllocator> const> ConstPtr;

}; // struct set_position_

typedef ::test::set_position_<std::allocator<void> > set_position;

typedef boost::shared_ptr< ::test::set_position > set_positionPtr;
typedef boost::shared_ptr< ::test::set_position const> set_positionConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::test::set_position_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::test::set_position_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::test::set_position_<ContainerAllocator1> & lhs, const ::test::set_position_<ContainerAllocator2> & rhs)
{
  return lhs.x == rhs.x &&
    lhs.y == rhs.y &&
    lhs.z == rhs.z &&
    lhs.flag1 == rhs.flag1;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::test::set_position_<ContainerAllocator1> & lhs, const ::test::set_position_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace test

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::test::set_position_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::test::set_position_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::test::set_position_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::test::set_position_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::test::set_position_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::test::set_position_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::test::set_position_<ContainerAllocator> >
{
  static const char* value()
  {
    return "5f7db468f1f67d536e537686487991cd";
  }

  static const char* value(const ::test::set_position_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x5f7db468f1f67d53ULL;
  static const uint64_t static_value2 = 0x6e537686487991cdULL;
};

template<class ContainerAllocator>
struct DataType< ::test::set_position_<ContainerAllocator> >
{
  static const char* value()
  {
    return "test/set_position";
  }

  static const char* value(const ::test::set_position_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::test::set_position_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32  x\n"
"float32  y\n"
"float32  z\n"
"float32 flag1\n"
"\n"
"\n"
;
  }

  static const char* value(const ::test::set_position_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::test::set_position_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.x);
      stream.next(m.y);
      stream.next(m.z);
      stream.next(m.flag1);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct set_position_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::test::set_position_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::test::set_position_<ContainerAllocator>& v)
  {
    s << indent << "x: ";
    Printer<float>::stream(s, indent + "  ", v.x);
    s << indent << "y: ";
    Printer<float>::stream(s, indent + "  ", v.y);
    s << indent << "z: ";
    Printer<float>::stream(s, indent + "  ", v.z);
    s << indent << "flag1: ";
    Printer<float>::stream(s, indent + "  ", v.flag1);
  }
};

} // namespace message_operations
} // namespace ros

#endif // TEST_MESSAGE_SET_POSITION_H
