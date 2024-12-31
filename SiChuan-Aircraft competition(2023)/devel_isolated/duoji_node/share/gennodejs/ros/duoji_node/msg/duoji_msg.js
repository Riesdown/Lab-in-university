// Auto-generated. Do not edit!

// (in-package duoji_node.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class duoji_msg {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.Duoji_angle = null;
    }
    else {
      if (initObj.hasOwnProperty('Duoji_angle')) {
        this.Duoji_angle = initObj.Duoji_angle
      }
      else {
        this.Duoji_angle = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type duoji_msg
    // Serialize message field [Duoji_angle]
    bufferOffset = _serializer.int32(obj.Duoji_angle, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type duoji_msg
    let len;
    let data = new duoji_msg(null);
    // Deserialize message field [Duoji_angle]
    data.Duoji_angle = _deserializer.int32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 4;
  }

  static datatype() {
    // Returns string type for a message object
    return 'duoji_node/duoji_msg';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '9bb68250934646b96771efd253d0ba16';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    int32 Duoji_angle
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new duoji_msg(null);
    if (msg.Duoji_angle !== undefined) {
      resolved.Duoji_angle = msg.Duoji_angle;
    }
    else {
      resolved.Duoji_angle = 0
    }

    return resolved;
    }
};

module.exports = duoji_msg;
