// Generated by gencpp from file test/send_positionResponse.msg
// DO NOT EDIT!


#ifndef TEST_MESSAGE_SEND_POSITIONRESPONSE_H
#define TEST_MESSAGE_SEND_POSITIONRESPONSE_H


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
struct send_positionResponse_
{
  typedef send_positionResponse_<ContainerAllocator> Type;

  send_positionResponse_()
    {
    }
  send_positionResponse_(const ContainerAllocator& _alloc)
    {
  (void)_alloc;
    }







  typedef boost::shared_ptr< ::test::send_positionResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::test::send_positionResponse_<ContainerAllocator> const> ConstPtr;

}; // struct send_positionResponse_

typedef ::test::send_positionResponse_<std::allocator<void> > send_positionResponse;

typedef boost::shared_ptr< ::test::send_positionResponse > send_positionResponsePtr;
typedef boost::shared_ptr< ::test::send_positionResponse const> send_positionResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::test::send_positionResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::test::send_positionResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


} // namespace test

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::test::send_positionResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::test::send_positionResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::test::send_positionResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::test::send_positionResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::test::send_positionResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::test::send_positionResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::test::send_positionResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d41d8cd98f00b204e9800998ecf8427e";
  }

  static const char* value(const ::test::send_positionResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd41d8cd98f00b204ULL;
  static const uint64_t static_value2 = 0xe9800998ecf8427eULL;
};

template<class ContainerAllocator>
struct DataType< ::test::send_positionResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "test/send_positionResponse";
  }

  static const char* value(const ::test::send_positionResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::test::send_positionResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n"
;
  }

  static const char* value(const ::test::send_positionResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::test::send_positionResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream&, T)
    {}

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct send_positionResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::test::send_positionResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream&, const std::string&, const ::test::send_positionResponse_<ContainerAllocator>&)
  {}
};

} // namespace message_operations
} // namespace ros

#endif // TEST_MESSAGE_SEND_POSITIONRESPONSE_H
