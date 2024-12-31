// Auto-generated. Do not edit!

// (in-package shijue_pkg.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class weizhi_data {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.wz_x = null;
      this.wz_y = null;
      this.flag = null;
    }
    else {
      if (initObj.hasOwnProperty('wz_x')) {
        this.wz_x = initObj.wz_x
      }
      else {
        this.wz_x = 0.0;
      }
      if (initObj.hasOwnProperty('wz_y')) {
        this.wz_y = initObj.wz_y
      }
      else {
        this.wz_y = 0.0;
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
    // Serializes a message object of type weizhi_data
    // Serialize message field [wz_x]
    bufferOffset = _serializer.float32(obj.wz_x, buffer, bufferOffset);
    // Serialize message field [wz_y]
    bufferOffset = _serializer.float32(obj.wz_y, buffer, bufferOffset);
    // Serialize message field [flag]
    bufferOffset = _serializer.bool(obj.flag, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type weizhi_data
    let len;
    let data = new weizhi_data(null);
    // Deserialize message field [wz_x]
    data.wz_x = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [wz_y]
    data.wz_y = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [flag]
    data.flag = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 9;
  }

  static datatype() {
    // Returns string type for a message object
    return 'shijue_pkg/weizhi_data';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '9352d5e7401b90403eb2ff4ec8292292';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float32 wz_x
    float32 wz_y
    bool flag
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new weizhi_data(null);
    if (msg.wz_x !== undefined) {
      resolved.wz_x = msg.wz_x;
    }
    else {
      resolved.wz_x = 0.0
    }

    if (msg.wz_y !== undefined) {
      resolved.wz_y = msg.wz_y;
    }
    else {
      resolved.wz_y = 0.0
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

module.exports = weizhi_data;
