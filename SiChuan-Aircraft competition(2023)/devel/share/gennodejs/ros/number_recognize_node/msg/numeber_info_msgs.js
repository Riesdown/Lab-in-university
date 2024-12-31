// Auto-generated. Do not edit!

// (in-package number_recognize_node.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class numeber_info_msgs {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.num = null;
      this.center_x = null;
      this.center_y = null;
      this.flag = null;
    }
    else {
      if (initObj.hasOwnProperty('num')) {
        this.num = initObj.num
      }
      else {
        this.num = 0;
      }
      if (initObj.hasOwnProperty('center_x')) {
        this.center_x = initObj.center_x
      }
      else {
        this.center_x = 0;
      }
      if (initObj.hasOwnProperty('center_y')) {
        this.center_y = initObj.center_y
      }
      else {
        this.center_y = 0;
      }
      if (initObj.hasOwnProperty('flag')) {
        this.flag = initObj.flag
      }
      else {
        this.flag = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type numeber_info_msgs
    // Serialize message field [num]
    bufferOffset = _serializer.int32(obj.num, buffer, bufferOffset);
    // Serialize message field [center_x]
    bufferOffset = _serializer.int32(obj.center_x, buffer, bufferOffset);
    // Serialize message field [center_y]
    bufferOffset = _serializer.int32(obj.center_y, buffer, bufferOffset);
    // Serialize message field [flag]
    bufferOffset = _serializer.bool(obj.flag, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type numeber_info_msgs
    let len;
    let data = new numeber_info_msgs(null);
    // Deserialize message field [num]
    data.num = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [center_x]
    data.center_x = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [center_y]
    data.center_y = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [flag]
    data.flag = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 13;
  }

  static datatype() {
    // Returns string type for a message object
    return 'number_recognize_node/numeber_info_msgs';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'd26e9a9b11d6e0b99d95bf5f9545549a';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int32 num
    int32 center_x
    int32 center_y
    bool flag
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new numeber_info_msgs(null);
    if (msg.num !== undefined) {
      resolved.num = msg.num;
    }
    else {
      resolved.num = 0
    }

    if (msg.center_x !== undefined) {
      resolved.center_x = msg.center_x;
    }
    else {
      resolved.center_x = 0
    }

    if (msg.center_y !== undefined) {
      resolved.center_y = msg.center_y;
    }
    else {
      resolved.center_y = 0
    }

    if (msg.flag !== undefined) {
      resolved.flag = msg.flag;
    }
    else {
      resolved.flag = false
    }

    return resolved;
    }
};

module.exports = numeber_info_msgs;
