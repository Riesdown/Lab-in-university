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

class navigation_ctrl {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.x = null;
      this.y = null;
      this.z = null;
      this.nav_mode = null;
      this.frame_id = null;
      this.num = null;
      this.execution_time = null;
      this.update_flag = null;
    }
    else {
      if (initObj.hasOwnProperty('x')) {
        this.x = initObj.x
      }
      else {
        this.x = 0.0;
      }
      if (initObj.hasOwnProperty('y')) {
        this.y = initObj.y
      }
      else {
        this.y = 0.0;
      }
      if (initObj.hasOwnProperty('z')) {
        this.z = initObj.z
      }
      else {
        this.z = 0.0;
      }
      if (initObj.hasOwnProperty('nav_mode')) {
        this.nav_mode = initObj.nav_mode
      }
      else {
        this.nav_mode = 0;
      }
      if (initObj.hasOwnProperty('frame_id')) {
        this.frame_id = initObj.frame_id
      }
      else {
        this.frame_id = 0;
      }
      if (initObj.hasOwnProperty('num')) {
        this.num = initObj.num
      }
      else {
        this.num = 0;
      }
      if (initObj.hasOwnProperty('execution_time')) {
        this.execution_time = initObj.execution_time
      }
      else {
        this.execution_time = 0;
      }
      if (initObj.hasOwnProperty('update_flag')) {
        this.update_flag = initObj.update_flag
      }
      else {
        this.update_flag = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type navigation_ctrl
    // Serialize message field [x]
    bufferOffset = _serializer.float32(obj.x, buffer, bufferOffset);
    // Serialize message field [y]
    bufferOffset = _serializer.float32(obj.y, buffer, bufferOffset);
    // Serialize message field [z]
    bufferOffset = _serializer.float32(obj.z, buffer, bufferOffset);
    // Serialize message field [nav_mode]
    bufferOffset = _serializer.uint8(obj.nav_mode, buffer, bufferOffset);
    // Serialize message field [frame_id]
    bufferOffset = _serializer.uint8(obj.frame_id, buffer, bufferOffset);
    // Serialize message field [num]
    bufferOffset = _serializer.uint16(obj.num, buffer, bufferOffset);
    // Serialize message field [execution_time]
    bufferOffset = _serializer.uint32(obj.execution_time, buffer, bufferOffset);
    // Serialize message field [update_flag]
    bufferOffset = _serializer.uint8(obj.update_flag, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type navigation_ctrl
    let len;
    let data = new navigation_ctrl(null);
    // Deserialize message field [x]
    data.x = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [y]
    data.y = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [z]
    data.z = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [nav_mode]
    data.nav_mode = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [frame_id]
    data.frame_id = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [num]
    data.num = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [execution_time]
    data.execution_time = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [update_flag]
    data.update_flag = _deserializer.uint8(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 21;
  }

  static datatype() {
    // Returns string type for a message object
    return 'user_messages/navigation_ctrl';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '57540d12dfd9892331224880fa18114a';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float32 x
    float32 y
    float32 z
    uint8 nav_mode
    uint8 frame_id
    uint16 num
    uint32 execution_time
    uint8 update_flag
    
    uint8 BODY_FRAME=0
    uint8 MAP_FRAME=1
    uint8 RELATIVE_MODE=0
    uint8 GLOBAL_MODE=1
    uint8 CMD_VEL_MODE=2
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new navigation_ctrl(null);
    if (msg.x !== undefined) {
      resolved.x = msg.x;
    }
    else {
      resolved.x = 0.0
    }

    if (msg.y !== undefined) {
      resolved.y = msg.y;
    }
    else {
      resolved.y = 0.0
    }

    if (msg.z !== undefined) {
      resolved.z = msg.z;
    }
    else {
      resolved.z = 0.0
    }

    if (msg.nav_mode !== undefined) {
      resolved.nav_mode = msg.nav_mode;
    }
    else {
      resolved.nav_mode = 0
    }

    if (msg.frame_id !== undefined) {
      resolved.frame_id = msg.frame_id;
    }
    else {
      resolved.frame_id = 0
    }

    if (msg.num !== undefined) {
      resolved.num = msg.num;
    }
    else {
      resolved.num = 0
    }

    if (msg.execution_time !== undefined) {
      resolved.execution_time = msg.execution_time;
    }
    else {
      resolved.execution_time = 0
    }

    if (msg.update_flag !== undefined) {
      resolved.update_flag = msg.update_flag;
    }
    else {
      resolved.update_flag = 0
    }

    return resolved;
    }
};

// Constants for message
navigation_ctrl.Constants = {
  BODY_FRAME: 0,
  MAP_FRAME: 1,
  RELATIVE_MODE: 0,
  GLOBAL_MODE: 1,
  CMD_VEL_MODE: 2,
}

module.exports = navigation_ctrl;
