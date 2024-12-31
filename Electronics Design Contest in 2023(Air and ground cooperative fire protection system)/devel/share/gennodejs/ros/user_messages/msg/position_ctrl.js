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

class position_ctrl {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.move_flag = null;
      this.move_order = null;
      this.move_distance = null;
    }
    else {
      if (initObj.hasOwnProperty('move_flag')) {
        this.move_flag = initObj.move_flag
      }
      else {
        this.move_flag = 0;
      }
      if (initObj.hasOwnProperty('move_order')) {
        this.move_order = initObj.move_order
      }
      else {
        this.move_order = 0;
      }
      if (initObj.hasOwnProperty('move_distance')) {
        this.move_distance = initObj.move_distance
      }
      else {
        this.move_distance = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type position_ctrl
    // Serialize message field [move_flag]
    bufferOffset = _serializer.uint8(obj.move_flag, buffer, bufferOffset);
    // Serialize message field [move_order]
    bufferOffset = _serializer.uint8(obj.move_order, buffer, bufferOffset);
    // Serialize message field [move_distance]
    bufferOffset = _serializer.uint16(obj.move_distance, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type position_ctrl
    let len;
    let data = new position_ctrl(null);
    // Deserialize message field [move_flag]
    data.move_flag = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [move_order]
    data.move_order = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [move_distance]
    data.move_distance = _deserializer.uint16(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 4;
  }

  static datatype() {
    // Returns string type for a message object
    return 'user_messages/position_ctrl';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '4b35dc4f304f0d5f7eaa8dda10fe4862';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    uint8 move_flag
    uint8 move_order
    uint16 move_distance
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new position_ctrl(null);
    if (msg.move_flag !== undefined) {
      resolved.move_flag = msg.move_flag;
    }
    else {
      resolved.move_flag = 0
    }

    if (msg.move_order !== undefined) {
      resolved.move_order = msg.move_order;
    }
    else {
      resolved.move_order = 0
    }

    if (msg.move_distance !== undefined) {
      resolved.move_distance = msg.move_distance;
    }
    else {
      resolved.move_distance = 0
    }

    return resolved;
    }
};

module.exports = position_ctrl;
