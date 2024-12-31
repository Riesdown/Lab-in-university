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

class arm_state {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.chess_aim_x = null;
      this.chess_aim_y = null;
    }
    else {
      if (initObj.hasOwnProperty('chess_aim_x')) {
        this.chess_aim_x = initObj.chess_aim_x
      }
      else {
        this.chess_aim_x = 0.0;
      }
      if (initObj.hasOwnProperty('chess_aim_y')) {
        this.chess_aim_y = initObj.chess_aim_y
      }
      else {
        this.chess_aim_y = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type arm_state
    // Serialize message field [chess_aim_x]
    bufferOffset = _serializer.float32(obj.chess_aim_x, buffer, bufferOffset);
    // Serialize message field [chess_aim_y]
    bufferOffset = _serializer.float32(obj.chess_aim_y, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type arm_state
    let len;
    let data = new arm_state(null);
    // Deserialize message field [chess_aim_x]
    data.chess_aim_x = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [chess_aim_y]
    data.chess_aim_y = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 8;
  }

  static datatype() {
    // Returns string type for a message object
    return 'test/arm_state';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '021ae4e1499fe0af22a25b5797cdfc12';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float32 chess_aim_x     # 棋子目的位置x
    float32 chess_aim_y     # 棋子目的位置y
    
    
    
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new arm_state(null);
    if (msg.chess_aim_x !== undefined) {
      resolved.chess_aim_x = msg.chess_aim_x;
    }
    else {
      resolved.chess_aim_x = 0.0
    }

    if (msg.chess_aim_y !== undefined) {
      resolved.chess_aim_y = msg.chess_aim_y;
    }
    else {
      resolved.chess_aim_y = 0.0
    }

    return resolved;
    }
};

module.exports = arm_state;
