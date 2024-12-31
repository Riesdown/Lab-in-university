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

class xc_kz_data {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.kz_str = null;
    }
    else {
      if (initObj.hasOwnProperty('kz_str')) {
        this.kz_str = initObj.kz_str
      }
      else {
        this.kz_str = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type xc_kz_data
    // Serialize message field [kz_str]
    bufferOffset = _serializer.string(obj.kz_str, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type xc_kz_data
    let len;
    let data = new xc_kz_data(null);
    // Deserialize message field [kz_str]
    data.kz_str = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.kz_str.length;
    return length + 4;
  }

  static datatype() {
    // Returns string type for a message object
    return 'lanya_pkg/xc_kz_data';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'faf6e880b42507c6d64b003da8b79bd3';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    string kz_str
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new xc_kz_data(null);
    if (msg.kz_str !== undefined) {
      resolved.kz_str = msg.kz_str;
    }
    else {
      resolved.kz_str = ''
    }

    return resolved;
    }
};

module.exports = xc_kz_data;
