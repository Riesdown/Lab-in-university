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

class fly_position {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.x1 = null;
      this.y1 = null;
      this.x2 = null;
      this.y2 = null;
      this.x3 = null;
      this.y3 = null;
      this.x4 = null;
      this.y4 = null;
      this.x5 = null;
      this.y5 = null;
      this.x6 = null;
      this.y6 = null;
    }
    else {
      if (initObj.hasOwnProperty('x1')) {
        this.x1 = initObj.x1
      }
      else {
        this.x1 = 0.0;
      }
      if (initObj.hasOwnProperty('y1')) {
        this.y1 = initObj.y1
      }
      else {
        this.y1 = 0.0;
      }
      if (initObj.hasOwnProperty('x2')) {
        this.x2 = initObj.x2
      }
      else {
        this.x2 = 0.0;
      }
      if (initObj.hasOwnProperty('y2')) {
        this.y2 = initObj.y2
      }
      else {
        this.y2 = 0.0;
      }
      if (initObj.hasOwnProperty('x3')) {
        this.x3 = initObj.x3
      }
      else {
        this.x3 = 0.0;
      }
      if (initObj.hasOwnProperty('y3')) {
        this.y3 = initObj.y3
      }
      else {
        this.y3 = 0.0;
      }
      if (initObj.hasOwnProperty('x4')) {
        this.x4 = initObj.x4
      }
      else {
        this.x4 = 0.0;
      }
      if (initObj.hasOwnProperty('y4')) {
        this.y4 = initObj.y4
      }
      else {
        this.y4 = 0.0;
      }
      if (initObj.hasOwnProperty('x5')) {
        this.x5 = initObj.x5
      }
      else {
        this.x5 = 0.0;
      }
      if (initObj.hasOwnProperty('y5')) {
        this.y5 = initObj.y5
      }
      else {
        this.y5 = 0.0;
      }
      if (initObj.hasOwnProperty('x6')) {
        this.x6 = initObj.x6
      }
      else {
        this.x6 = 0.0;
      }
      if (initObj.hasOwnProperty('y6')) {
        this.y6 = initObj.y6
      }
      else {
        this.y6 = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type fly_position
    // Serialize message field [x1]
    bufferOffset = _serializer.float32(obj.x1, buffer, bufferOffset);
    // Serialize message field [y1]
    bufferOffset = _serializer.float32(obj.y1, buffer, bufferOffset);
    // Serialize message field [x2]
    bufferOffset = _serializer.float32(obj.x2, buffer, bufferOffset);
    // Serialize message field [y2]
    bufferOffset = _serializer.float32(obj.y2, buffer, bufferOffset);
    // Serialize message field [x3]
    bufferOffset = _serializer.float32(obj.x3, buffer, bufferOffset);
    // Serialize message field [y3]
    bufferOffset = _serializer.float32(obj.y3, buffer, bufferOffset);
    // Serialize message field [x4]
    bufferOffset = _serializer.float32(obj.x4, buffer, bufferOffset);
    // Serialize message field [y4]
    bufferOffset = _serializer.float32(obj.y4, buffer, bufferOffset);
    // Serialize message field [x5]
    bufferOffset = _serializer.float32(obj.x5, buffer, bufferOffset);
    // Serialize message field [y5]
    bufferOffset = _serializer.float32(obj.y5, buffer, bufferOffset);
    // Serialize message field [x6]
    bufferOffset = _serializer.float32(obj.x6, buffer, bufferOffset);
    // Serialize message field [y6]
    bufferOffset = _serializer.float32(obj.y6, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type fly_position
    let len;
    let data = new fly_position(null);
    // Deserialize message field [x1]
    data.x1 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [y1]
    data.y1 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [x2]
    data.x2 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [y2]
    data.y2 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [x3]
    data.x3 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [y3]
    data.y3 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [x4]
    data.x4 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [y4]
    data.y4 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [x5]
    data.x5 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [y5]
    data.y5 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [x6]
    data.x6 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [y6]
    data.y6 = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 48;
  }

  static datatype() {
    // Returns string type for a message object
    return 'test/fly_position';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'd3c31e442f291e7849f095629277239d';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float32  x1
    float32  y1
    
    float32  x2
    float32  y2
    
    float32  x3
    float32  y3
    
    float32  x4
    float32  y4
    
    float32  x5
    float32  y5
    
    float32  x6
    float32  y6
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new fly_position(null);
    if (msg.x1 !== undefined) {
      resolved.x1 = msg.x1;
    }
    else {
      resolved.x1 = 0.0
    }

    if (msg.y1 !== undefined) {
      resolved.y1 = msg.y1;
    }
    else {
      resolved.y1 = 0.0
    }

    if (msg.x2 !== undefined) {
      resolved.x2 = msg.x2;
    }
    else {
      resolved.x2 = 0.0
    }

    if (msg.y2 !== undefined) {
      resolved.y2 = msg.y2;
    }
    else {
      resolved.y2 = 0.0
    }

    if (msg.x3 !== undefined) {
      resolved.x3 = msg.x3;
    }
    else {
      resolved.x3 = 0.0
    }

    if (msg.y3 !== undefined) {
      resolved.y3 = msg.y3;
    }
    else {
      resolved.y3 = 0.0
    }

    if (msg.x4 !== undefined) {
      resolved.x4 = msg.x4;
    }
    else {
      resolved.x4 = 0.0
    }

    if (msg.y4 !== undefined) {
      resolved.y4 = msg.y4;
    }
    else {
      resolved.y4 = 0.0
    }

    if (msg.x5 !== undefined) {
      resolved.x5 = msg.x5;
    }
    else {
      resolved.x5 = 0.0
    }

    if (msg.y5 !== undefined) {
      resolved.y5 = msg.y5;
    }
    else {
      resolved.y5 = 0.0
    }

    if (msg.x6 !== undefined) {
      resolved.x6 = msg.x6;
    }
    else {
      resolved.x6 = 0.0
    }

    if (msg.y6 !== undefined) {
      resolved.y6 = msg.y6;
    }
    else {
      resolved.y6 = 0.0
    }

    return resolved;
    }
};

module.exports = fly_position;
