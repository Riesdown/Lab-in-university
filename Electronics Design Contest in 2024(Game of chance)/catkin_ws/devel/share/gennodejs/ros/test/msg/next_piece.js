// Auto-generated. Do not edit!

// (in-package test.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class next_piece {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.next = null;
    }
    else {
      if (initObj.hasOwnProperty('next')) {
        this.next = initObj.next
      }
      else {
        this.next = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type next_piece
    // Serialize message field [next]
    bufferOffset = _serializer.int32(obj.next, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type next_piece
    let len;
    let data = new next_piece(null);
    // Deserialize message field [next]
    data.next = _deserializer.int32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 4;
  }

  static datatype() {
    // Returns string type for a message object
    return 'test/next_piece';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '89e3abdd267d92f91c4ae5f000c4dde5';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int32 next
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new next_piece(null);
    if (msg.next !== undefined) {
      resolved.next = msg.next;
    }
    else {
      resolved.next = 0
    }

    return resolved;
    }
};

module.exports = next_piece;
