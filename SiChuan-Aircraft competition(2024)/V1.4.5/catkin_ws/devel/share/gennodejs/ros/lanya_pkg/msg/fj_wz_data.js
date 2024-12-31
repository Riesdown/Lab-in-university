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

class fj_wz_data {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.fj_x = null;
      this.fj_y = null;
    }
    else {
      if (initObj.hasOwnProperty('fj_x')) {
        this.fj_x = initObj.fj_x
      }
      else {
        this.fj_x = 0.0;
      }
      if (initObj.hasOwnProperty('fj_y')) {
        this.fj_y = initObj.fj_y
      }
      else {
        this.fj_y = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type fj_wz_data
    // Serialize message field [fj_x]
    bufferOffset = _serializer.float32(obj.fj_x, buffer, bufferOffset);
    // Serialize message field [fj_y]
    bufferOffset = _serializer.float32(obj.fj_y, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type fj_wz_data
    let len;
    let data = new fj_wz_data(null);
    // Deserialize message field [fj_x]
    data.fj_x = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [fj_y]
    data.fj_y = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 8;
  }

  static datatype() {
    // Returns string type for a message object
    return 'lanya_pkg/fj_wz_data';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '11a2e9cf43a8ca7a8685679601c4ed90';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float32 fj_x
    float32 fj_y
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new fj_wz_data(null);
    if (msg.fj_x !== undefined) {
      resolved.fj_x = msg.fj_x;
    }
    else {
      resolved.fj_x = 0.0
    }

    if (msg.fj_y !== undefined) {
      resolved.fj_y = msg.fj_y;
    }
    else {
      resolved.fj_y = 0.0
    }

    return resolved;
    }
};

module.exports = fj_wz_data;
