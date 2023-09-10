# DO NOT EDIT! This file was auto-generated by crates/re_types_builder/src/codegen/python.rs

from __future__ import annotations

from typing import Sequence, Union

import pyarrow as pa
from attrs import define, field

from .. import datatypes
from .._baseclasses import (
    BaseExtensionArray,
    BaseExtensionType,
)
from ._overrides import rotationaxisangle_angle_converter  # noqa: F401

__all__ = [
    "RotationAxisAngle",
    "RotationAxisAngleArray",
    "RotationAxisAngleArrayLike",
    "RotationAxisAngleLike",
    "RotationAxisAngleType",
]


def _rotationaxisangle_axis_converter(x: datatypes.Vec3DLike) -> datatypes.Vec3D:
    if isinstance(x, datatypes.Vec3D):
        return x
    else:
        return datatypes.Vec3D(x)


@define
class RotationAxisAngle:
    """3D rotation represented by a rotation around a given axis."""

    axis: datatypes.Vec3D = field(converter=_rotationaxisangle_axis_converter)
    """
    Axis to rotate around.

    This is not required to be normalized.
    If normalization fails (typically because the vector is length zero), the rotation is silently
    ignored.
    """

    angle: datatypes.Angle = field(converter=rotationaxisangle_angle_converter)
    """
    How much to rotate around the axis.
    """


RotationAxisAngleLike = RotationAxisAngle
RotationAxisAngleArrayLike = Union[
    RotationAxisAngle,
    Sequence[RotationAxisAngleLike],
]


# --- Arrow support ---


class RotationAxisAngleType(BaseExtensionType):
    def __init__(self) -> None:
        pa.ExtensionType.__init__(
            self,
            pa.struct(
                [
                    pa.field(
                        "axis",
                        pa.list_(pa.field("item", pa.float32(), nullable=False, metadata={}), 3),
                        nullable=False,
                        metadata={},
                    ),
                    pa.field(
                        "angle",
                        pa.dense_union(
                            [
                                pa.field("_null_markers", pa.null(), nullable=True, metadata={}),
                                pa.field("Radians", pa.float32(), nullable=False, metadata={}),
                                pa.field("Degrees", pa.float32(), nullable=False, metadata={}),
                            ]
                        ),
                        nullable=False,
                        metadata={},
                    ),
                ]
            ),
            "rerun.datatypes.RotationAxisAngle",
        )


class RotationAxisAngleArray(BaseExtensionArray[RotationAxisAngleArrayLike]):
    _EXTENSION_NAME = "rerun.datatypes.RotationAxisAngle"
    _EXTENSION_TYPE = RotationAxisAngleType

    @staticmethod
    def _native_to_pa_array(data: RotationAxisAngleArrayLike, data_type: pa.DataType) -> pa.Array:
        raise NotImplementedError  # You need to implement "rotationaxisangle_native_to_pa_array" in rerun_py/rerun_sdk/rerun/_rerun2/datatypes/_overrides/rotation_axis_angle.py


RotationAxisAngleType._ARRAY_TYPE = RotationAxisAngleArray

# TODO(cmc): bring back registration to pyarrow once legacy types are gone
# pa.register_extension_type(RotationAxisAngleType())
