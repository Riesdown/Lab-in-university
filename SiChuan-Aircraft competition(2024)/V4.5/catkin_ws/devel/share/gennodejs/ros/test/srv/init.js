// Auto-generated. Do not edit!

// (in-package test.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------


//-----------------------------------------------------------

class initRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.h1 = null;
      this.h2 = null;
      this.w_l = null;
      this.w_r = null;
    }
    else {
      if (initObj.hasOwnProperty('h1')) {
        this.h1 = initObj.h1
      }
      else {
        this.h1 = 0.0;
      }
      if (initObj.hasOwnProperty('h2')) {
        this.h2 = initObj.h2
      }
      else {
        this.h2 = 0.0;
      }
      if (initObj.hasOwnProperty('w_l')) {
        this.w_l = initObj.w_l
      }
      else {
        this.w_l = 0.0;
      }
      if (initObj.hasOwnProperty('w_r')) {
        this.w_r = initObj.w_r
      }
      else {
        this.w_r = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type initRequest
    // Serialize message field [h1]
    bufferOffset = _serializer.float32(obj.h1, buffer, bufferOffset);
    // Serialize message field [h2]
    bufferOffset = _serializer.float32(obj.h2, buffer, bufferOffset);
    // Serialize message field [w_l]
    bufferOffset = _serializer.float32(obj.w_l, buffer, bufferOffset);
    // Serialize message field [w_r]
    bufferOffset = _serializer.float32(obj.w_r, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type initRequest
    let len;
    let data = new initRequest(null);
    // Deserialize message field [h1]
    data.h1 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [h2]
    data.h2 = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [w_l]
    data.w_l = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [w_r]
    data.w_r = _deserializer.float32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 16;
  }

  static datatype() {
    // Returns string type for a service object
    return 'test/initRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'b9f244da9d660c74ffc1e6ba8395f7c7';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float32 h1
    float32 h2
    
    float32 w_l
    float32 w_r
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new initRequest(null);
    if (msg.h1 !== undefined) {
      resolved.h1 = msg.h1;
    }
    else {
      resolved.h1 = 0.0
    }

    if (msg.h2 !== undefined) {
      resolved.h2 = msg.h2;
    }
    else {
      resolved.h2 = 0.0
    }

    if (msg.w_l !== undefined) {
      resolved.w_l = msg.w_l;
    }
    else {
      resolved.w_l = 0.0
    }

    if (msg.w_r !== undefined) {
      resolved.w_r = msg.w_r;
    }
    else {
      resolved.w_r = 0.0
    }

    return resolved;
    }
};

class initResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.success = null;
    }
    else {
      if (initObj.hasOwnProperty('success')) {
        this.success = initObj.success
      }
      else {
        this.success = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type initResponse
    // Serialize message field [success]
    bufferOffset = _serializer.bool(obj.success, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type initResponse
    let len;
    let data = new initResponse(null);
    // Deserialize message field [success]
    data.success = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 1;
  }

  static datatype() {
    // Returns string type for a service object
    return 'test/initResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '358e233cde0c8a8bcfea4ce193f8fc15';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool success
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new initResponse(null);
    if (msg.success !== undefined) {
      resolved.success = msg.success;
    }
    else {
      resolved.success = false
    }

    return resolved;
    }
};

module.exports = {
  Request: initRequest,
  Response: initResponse,
  md5sum() { return '642f7aacdf0e5b4d32599cf72b5a2ba9'; },
  datatype() { return 'test/init'; }
};
