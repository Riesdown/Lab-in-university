# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from serialport/position_cmd.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class position_cmd(genpy.Message):
  _md5sum = "4b35dc4f304f0d5f7eaa8dda10fe4862"
  _type = "serialport/position_cmd"
  _has_header = False  # flag to mark the presence of a Header object
  _full_text = """uint8 move_flag
uint8 move_order
uint16 move_distance
"""
  __slots__ = ['move_flag','move_order','move_distance']
  _slot_types = ['uint8','uint8','uint16']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       move_flag,move_order,move_distance

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(position_cmd, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.move_flag is None:
        self.move_flag = 0
      if self.move_order is None:
        self.move_order = 0
      if self.move_distance is None:
        self.move_distance = 0
    else:
      self.move_flag = 0
      self.move_order = 0
      self.move_distance = 0

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self
      buff.write(_get_struct_2BH().pack(_x.move_flag, _x.move_order, _x.move_distance))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    if python3:
      codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      end = 0
      _x = self
      start = end
      end += 4
      (_x.move_flag, _x.move_order, _x.move_distance,) = _get_struct_2BH().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self
      buff.write(_get_struct_2BH().pack(_x.move_flag, _x.move_order, _x.move_distance))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    if python3:
      codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      end = 0
      _x = self
      start = end
      end += 4
      (_x.move_flag, _x.move_order, _x.move_distance,) = _get_struct_2BH().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_2BH = None
def _get_struct_2BH():
    global _struct_2BH
    if _struct_2BH is None:
        _struct_2BH = struct.Struct("<2BH")
    return _struct_2BH
