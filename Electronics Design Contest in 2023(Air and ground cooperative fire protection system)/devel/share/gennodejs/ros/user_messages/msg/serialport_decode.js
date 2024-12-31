// Auto-generated. Do not edit!

// (in-package user_messages.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class serialport_decode {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.buf = null;
      this.cnt = null;
    }
    else {
      if (initObj.hasOwnProperty('buf')) {
        this.buf = initObj.buf
      }
      else {
        this.buf = [];
      }
      if (initObj.hasOwnProperty('cnt')) {
        this.cnt = initObj.cnt
      }
      else {
        this.cnt = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type serialport_decode
    // Serialize message field [buf]
    bufferOffset = _arraySerializer.uint8(obj.buf, buffer, bufferOffset, null);
    // Serialize message field [cnt]
    bufferOffset = _serializer.uint16(obj.cnt, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type serialport_decode
    let len;
    let data = new serialport_decode(null);
    // Deserialize message field [buf]
    data.buf = _arrayDeserializer.uint8(buffer, bufferOffset, null)
    // Deserialize message field [cnt]
    data.cnt = _deserializer.uint16(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += object.buf.length;
    return length + 6;
  }

  static datatype() {
    // Returns string type for a message object
    return 'user_messages/serialport_decode';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'b64998cbe9ab1eb940716392cc08fe66';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    uint8[] buf
    uint16 cnt
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new serialport_decode(null);
    if (msg.buf !== undefined) {
      resolved.buf = msg.buf;
    }
    else {
      resolved.buf = []
    }

    if (msg.cnt !== undefined) {
      resolved.cnt = msg.cnt;
    }
    else {
      resolved.cnt = 0
    }

    return resolved;
    }
};

module.exports = serialport_decode;
