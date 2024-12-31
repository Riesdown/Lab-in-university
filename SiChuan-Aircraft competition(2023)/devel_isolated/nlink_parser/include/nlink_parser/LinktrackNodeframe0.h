// Generated by gencpp from file nlink_parser/LinktrackNodeframe0.msg
// DO NOT EDIT!


#ifndef NLINK_PARSER_MESSAGE_LINKTRACKNODEFRAME0_H
#define NLINK_PARSER_MESSAGE_LINKTRACKNODEFRAME0_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <nlink_parser/LinktrackNode0.h>

namespace nlink_parser
{
template <class ContainerAllocator>
struct LinktrackNodeframe0_
{
  typedef LinktrackNodeframe0_<ContainerAllocator> Type;

  LinktrackNodeframe0_()
    : role(0)
    , id(0)
    , nodes()  {
    }
  LinktrackNodeframe0_(const ContainerAllocator& _alloc)
    : role(0)
    , id(0)
    , nodes(_alloc)  {
  (void)_alloc;
    }



   typedef uint8_t _role_type;
  _role_type role;

   typedef uint8_t _id_type;
  _id_type id;

   typedef std::vector< ::nlink_parser::LinktrackNode0_<ContainerAllocator> , typename std::allocator_traits<ContainerAllocator>::template rebind_alloc< ::nlink_parser::LinktrackNode0_<ContainerAllocator> >> _nodes_type;
  _nodes_type nodes;





  typedef boost::shared_ptr< ::nlink_parser::LinktrackNodeframe0_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::nlink_parser::LinktrackNodeframe0_<ContainerAllocator> const> ConstPtr;

}; // struct LinktrackNodeframe0_

typedef ::nlink_parser::LinktrackNodeframe0_<std::allocator<void> > LinktrackNodeframe0;

typedef boost::shared_ptr< ::nlink_parser::LinktrackNodeframe0 > LinktrackNodeframe0Ptr;
typedef boost::shared_ptr< ::nlink_parser::LinktrackNodeframe0 const> LinktrackNodeframe0ConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::nlink_parser::LinktrackNodeframe0_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::nlink_parser::LinktrackNodeframe0_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::nlink_parser::LinktrackNodeframe0_<ContainerAllocator1> & lhs, const ::nlink_parser::LinktrackNodeframe0_<ContainerAllocator2> & rhs)
{
  return lhs.role == rhs.role &&
    lhs.id == rhs.id &&
    lhs.nodes == rhs.nodes;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::nlink_parser::LinktrackNodeframe0_<ContainerAllocator1> & lhs, const ::nlink_parser::LinktrackNodeframe0_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace nlink_parser

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::nlink_parser::LinktrackNodeframe0_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::nlink_parser::LinktrackNodeframe0_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::nlink_parser::LinktrackNodeframe0_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::nlink_parser::LinktrackNodeframe0_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::nlink_parser::LinktrackNodeframe0_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::nlink_parser::LinktrackNodeframe0_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::nlink_parser::LinktrackNodeframe0_<ContainerAllocator> >
{
  static const char* value()
  {
    return "99d2eee732fdf2fb898d64e9172d0e66";
  }

  static const char* value(const ::nlink_parser::LinktrackNodeframe0_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x99d2eee732fdf2fbULL;
  static const uint64_t static_value2 = 0x898d64e9172d0e66ULL;
};

template<class ContainerAllocator>
struct DataType< ::nlink_parser::LinktrackNodeframe0_<ContainerAllocator> >
{
  static const char* value()
  {
    return "nlink_parser/LinktrackNodeframe0";
  }

  static const char* value(const ::nlink_parser::LinktrackNodeframe0_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::nlink_parser::LinktrackNodeframe0_<ContainerAllocator> >
{
  static const char* value()
  {
    return "uint8 role\n"
"uint8 id\n"
"LinktrackNode0[] nodes\n"
"\n"
"================================================================================\n"
"MSG: nlink_parser/LinktrackNode0\n"
"uint8 role\n"
"uint8 id\n"
"uint8[] data\n"
;
  }

  static const char* value(const ::nlink_parser::LinktrackNodeframe0_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::nlink_parser::LinktrackNodeframe0_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.role);
      stream.next(m.id);
      stream.next(m.nodes);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct LinktrackNodeframe0_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::nlink_parser::LinktrackNodeframe0_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::nlink_parser::LinktrackNodeframe0_<ContainerAllocator>& v)
  {
    s << indent << "role: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.role);
    s << indent << "id: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.id);
    s << indent << "nodes[]" << std::endl;
    for (size_t i = 0; i < v.nodes.size(); ++i)
    {
      s << indent << "  nodes[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::nlink_parser::LinktrackNode0_<ContainerAllocator> >::stream(s, indent + "    ", v.nodes[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // NLINK_PARSER_MESSAGE_LINKTRACKNODEFRAME0_H