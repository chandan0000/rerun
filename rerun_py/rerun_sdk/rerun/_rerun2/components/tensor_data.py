# DO NOT EDIT! This file was auto-generated by crates/re_types_builder/src/codegen/python.rs

from __future__ import annotations

from .. import datatypes
from .._baseclasses import (
    BaseDelegatingExtensionArray,
    BaseDelegatingExtensionType,
)

__all__ = ["TensorDataArray", "TensorDataType"]


class TensorDataType(BaseDelegatingExtensionType):
    _TYPE_NAME = "rerun.components.TensorData"
    _DELEGATED_EXTENSION_TYPE = datatypes.TensorDataType


class TensorDataArray(BaseDelegatingExtensionArray[datatypes.TensorDataArrayLike]):
    _EXTENSION_NAME = "rerun.components.TensorData"
    _EXTENSION_TYPE = TensorDataType
    _DELEGATED_ARRAY_TYPE = datatypes.TensorDataArray


TensorDataType._ARRAY_TYPE = TensorDataArray

# TODO(cmc): bring back registration to pyarrow once legacy types are gone
# pa.register_extension_type(TensorDataType())
