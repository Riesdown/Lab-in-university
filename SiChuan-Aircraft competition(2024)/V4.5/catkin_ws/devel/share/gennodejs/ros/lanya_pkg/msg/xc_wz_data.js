// Auto-generated. Do not edit!

// (in-package lanya_pkg.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class xc_wz_data {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.xc_x = null;
      this.xc_y = null;
    }
    else {
      if (initObj.hasOwnProperty('xc_x')) {
        this.xc_x = initObj.xc_x
      }
      else {
        this.xc_x = 0.0;
      }
      if (initObj.hasOwnProperty('xc_y')) {
        this.xc_y = initObj.xc_y
      }
      else {
        this.xc_y = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type xc_wz_data
    // Serialize message field [xc_x]
    bufferOffset = _serializer.float32(obj.xc_x, buffer, bufferOffset);
    // Serialize message field [xc_y]
    bufferOffset = _serializer.float32(obj.xc_y, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type xc_wz_data
    let len;
    let data = new xc_wz_data(null);
    // Deserialize message field [xc_x]
    data.xc_x = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [xc_y]
    data.xc_y = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 8;
  }

  static datatype() {
    // Returns string type for a message object
    return 'lanya_pkg/xc_wz_data';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '0af5983c67c5a0659bc718afae52c5bd';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float32 xc_x
    float32 xc_y
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new xc_wz_data(null);
    if (msg.xc_x !== undefined) {
      resolved.xc_x = msg.xc_x;
    }
    else {
      resolved.xc_x = 0.0
    }

    if (msg.xc_y !== undefined) {
      resolved.xc_y = msg.xc_y;
    }
    else {
      resolved.xc_y = 0.0
    }

    return resolved;
    }
};

module.exports = xc_wz_data;
