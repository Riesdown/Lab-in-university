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

class key_send {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.chess_change = null;
      this.chess_num = null;
      this.position = null;
    }
    else {
      if (initObj.hasOwnProperty('chess_change')) {
        this.chess_change = initObj.chess_change
      }
      else {
        this.chess_change = 0;
      }
      if (initObj.hasOwnProperty('chess_num')) {
        this.chess_num = initObj.chess_num
      }
      else {
        this.chess_num = 0;
      }
      if (initObj.hasOwnProperty('position')) {
        this.position = initObj.position
      }
      else {
        this.position = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type key_send
    // Serialize message field [chess_change]
    bufferOffset = _serializer.int32(obj.chess_change, buffer, bufferOffset);
    // Serialize message field [chess_num]
    bufferOffset = _serializer.int32(obj.chess_num, buffer, bufferOffset);
    // Serialize message field [position]
    bufferOffset = _serializer.int32(obj.position, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type key_send
    let len;
    let data = new key_send(null);
    // Deserialize message field [chess_change]
    data.chess_change = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [chess_num]
    data.chess_num = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [position]
    data.position = _deserializer.int32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 12;
  }

  static datatype() {
    // Returns string type for a message object
    return 'test/key_send';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '1f77ffe24d4ef0b7fc703ecd866700bb';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int32 chess_change      # 棋子改变
    int32 chess_num         # 棋子编号
    int32 position          # 位置
    
    
    
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new key_send(null);
    if (msg.chess_change !== undefined) {
      resolved.chess_change = msg.chess_change;
    }
    else {
      resolved.chess_change = 0
    }

    if (msg.chess_num !== undefined) {
      resolved.chess_num = msg.chess_num;
    }
    else {
      resolved.chess_num = 0
    }

    if (msg.position !== undefined) {
      resolved.position = msg.position;
    }
    else {
      resolved.position = 0
    }

    return resolved;
    }
};

module.exports = key_send;
