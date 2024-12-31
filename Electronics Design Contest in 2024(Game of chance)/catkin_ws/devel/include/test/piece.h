// Generated by gencpp from file test/piece.msg
// DO NOT EDIT!


#ifndef TEST_MESSAGE_PIECE_H
#define TEST_MESSAGE_PIECE_H


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
struct piece_
{
  typedef piece_<ContainerAllocator> Type;

  piece_()
    : angle(0.0)
    , id(0)
    , status(0)  {
    }
  piece_(const ContainerAllocator& _alloc)
    : angle(0.0)
    , id(0)
    , status(0)  {
  (void)_alloc;
    }



   typedef float _angle_type;
  _angle_type angle;

   typedef int32_t _id_type;
  _id_type id;

   typedef int32_t _status_type;
  _status_type status;





  typedef boost::shared_ptr< ::test::piece_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::test::piece_<ContainerAllocator> const> ConstPtr;

}; // struct piece_

typedef ::test::piece_<std::allocator<void> > piece;

typedef boost::shared_ptr< ::test::piece > piecePtr;
typedef boost::shared_ptr< ::test::piece const> pieceConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::test::piece_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::test::piece_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::test::piece_<ContainerAllocator1> & lhs, const ::test::piece_<ContainerAllocator2> & rhs)
{
  return lhs.angle == rhs.angle &&
    lhs.id == rhs.id &&
    lhs.status == rhs.status;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::test::piece_<ContainerAllocator1> & lhs, const ::test::piece_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace test

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::test::piece_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::test::piece_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::test::piece_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::test::piece_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::test::piece_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::test::piece_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::test::piece_<ContainerAllocator> >
{
  static const char* value()
  {
    return "306bc2650a33dfc448b8d4bd5ce5a685";
  }

  static const char* value(const ::test::piece_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x306bc2650a33dfc4ULL;
  static const uint64_t static_value2 = 0x48b8d4bd5ce5a685ULL;
};

template<class ContainerAllocator>
struct DataType< ::test::piece_<ContainerAllocator> >
{
  static const char* value()
  {
    return "test/piece";
  }

  static const char* value(const ::test::piece_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::test::piece_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32 angle   # 旋转角度\n"
"int32 id        # 方格ID\n"
"int32 status    # 小格状态\n"
"\n"
"\n"
;
  }

  static const char* value(const ::test::piece_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::test::piece_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.angle);
      stream.next(m.id);
      stream.next(m.status);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct piece_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::test::piece_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::test::piece_<ContainerAllocator>& v)
  {
    s << indent << "angle: ";
    Printer<float>::stream(s, indent + "  ", v.angle);
    s << indent << "id: ";
    Printer<int32_t>::stream(s, indent + "  ", v.id);
    s << indent << "status: ";
    Printer<int32_t>::stream(s, indent + "  ", v.status);
  }
};

} // namespace message_operations
} // namespace ros

#endif // TEST_MESSAGE_PIECE_H