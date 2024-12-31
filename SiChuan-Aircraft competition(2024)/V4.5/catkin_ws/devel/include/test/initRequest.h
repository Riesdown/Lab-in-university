// Generated by gencpp from file test/initRequest.msg
// DO NOT EDIT!


#ifndef TEST_MESSAGE_INITREQUEST_H
#define TEST_MESSAGE_INITREQUEST_H


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
struct initRequest_
{
  typedef initRequest_<ContainerAllocator> Type;

  initRequest_()
    : h1(0.0)
    , h2(0.0)
    , w_l(0.0)
    , w_r(0.0)  {
    }
  initRequest_(const ContainerAllocator& _alloc)
    : h1(0.0)
    , h2(0.0)
    , w_l(0.0)
    , w_r(0.0)  {
  (void)_alloc;
    }



   typedef float _h1_type;
  _h1_type h1;

   typedef float _h2_type;
  _h2_type h2;

   typedef float _w_l_type;
  _w_l_type w_l;

   typedef float _w_r_type;
  _w_r_type w_r;





  typedef boost::shared_ptr< ::test::initRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::test::initRequest_<ContainerAllocator> const> ConstPtr;

}; // struct initRequest_

typedef ::test::initRequest_<std::allocator<void> > initRequest;

typedef boost::shared_ptr< ::test::initRequest > initRequestPtr;
typedef boost::shared_ptr< ::test::initRequest const> initRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::test::initRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::test::initRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::test::initRequest_<ContainerAllocator1> & lhs, const ::test::initRequest_<ContainerAllocator2> & rhs)
{
  return lhs.h1 == rhs.h1 &&
    lhs.h2 == rhs.h2 &&
    lhs.w_l == rhs.w_l &&
    lhs.w_r == rhs.w_r;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::test::initRequest_<ContainerAllocator1> & lhs, const ::test::initRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace test

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::test::initRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::test::initRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::test::initRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::test::initRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::test::initRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::test::initRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::test::initRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "b9f244da9d660c74ffc1e6ba8395f7c7";
  }

  static const char* value(const ::test::initRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xb9f244da9d660c74ULL;
  static const uint64_t static_value2 = 0xffc1e6ba8395f7c7ULL;
};

template<class ContainerAllocator>
struct DataType< ::test::initRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "test/initRequest";
  }

  static const char* value(const ::test::initRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::test::initRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32 h1\n"
"float32 h2\n"
"\n"
"float32 w_l\n"
"float32 w_r\n"
;
  }

  static const char* value(const ::test::initRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::test::initRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.h1);
      stream.next(m.h2);
      stream.next(m.w_l);
      stream.next(m.w_r);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct initRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::test::initRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::test::initRequest_<ContainerAllocator>& v)
  {
    s << indent << "h1: ";
    Printer<float>::stream(s, indent + "  ", v.h1);
    s << indent << "h2: ";
    Printer<float>::stream(s, indent + "  ", v.h2);
    s << indent << "w_l: ";
    Printer<float>::stream(s, indent + "  ", v.w_l);
    s << indent << "w_r: ";
    Printer<float>::stream(s, indent + "  ", v.w_r);
  }
};

} // namespace message_operations
} // namespace ros

#endif // TEST_MESSAGE_INITREQUEST_H