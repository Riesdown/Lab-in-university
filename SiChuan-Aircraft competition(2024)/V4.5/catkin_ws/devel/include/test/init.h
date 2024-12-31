// Generated by gencpp from file test/init.msg
// DO NOT EDIT!


#ifndef TEST_MESSAGE_INIT_H
#define TEST_MESSAGE_INIT_H

#include <ros/service_traits.h>


#include <test/initRequest.h>
#include <test/initResponse.h>


namespace test
{

struct init
{

typedef initRequest Request;
typedef initResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct init
} // namespace test


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::test::init > {
  static const char* value()
  {
    return "642f7aacdf0e5b4d32599cf72b5a2ba9";
  }

  static const char* value(const ::test::init&) { return value(); }
};

template<>
struct DataType< ::test::init > {
  static const char* value()
  {
    return "test/init";
  }

  static const char* value(const ::test::init&) { return value(); }
};


// service_traits::MD5Sum< ::test::initRequest> should match
// service_traits::MD5Sum< ::test::init >
template<>
struct MD5Sum< ::test::initRequest>
{
  static const char* value()
  {
    return MD5Sum< ::test::init >::value();
  }
  static const char* value(const ::test::initRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::test::initRequest> should match
// service_traits::DataType< ::test::init >
template<>
struct DataType< ::test::initRequest>
{
  static const char* value()
  {
    return DataType< ::test::init >::value();
  }
  static const char* value(const ::test::initRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::test::initResponse> should match
// service_traits::MD5Sum< ::test::init >
template<>
struct MD5Sum< ::test::initResponse>
{
  static const char* value()
  {
    return MD5Sum< ::test::init >::value();
  }
  static const char* value(const ::test::initResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::test::initResponse> should match
// service_traits::DataType< ::test::init >
template<>
struct DataType< ::test::initResponse>
{
  static const char* value()
  {
    return DataType< ::test::init >::value();
  }
  static const char* value(const ::test::initResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // TEST_MESSAGE_INIT_H