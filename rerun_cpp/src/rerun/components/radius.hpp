// DO NOT EDIT! This file was auto-generated by crates/re_types_builder/src/codegen/cpp/mod.rs
// Based on "crates/re_types/definitions/rerun/components/radius.fbs".

#pragma once

#include "../data_cell.hpp"
#include "../result.hpp"

#include <cstdint>
#include <memory>
#include <utility>

namespace arrow {
    template <typename T>
    class NumericBuilder;

    class DataType;
    class FloatType;
    class MemoryPool;
    using FloatBuilder = NumericBuilder<FloatType>;
} // namespace arrow

namespace rerun {
    namespace components {
        /// A Radius component.
        struct Radius {
            float value;

            /// Name of the component, used for serialization.
            static const char NAME[];

          public:
            Radius() = default;

            Radius(float _value) : value(std::move(_value)) {}

            Radius& operator=(float _value) {
                value = std::move(_value);
                return *this;
            }

            /// Returns the arrow data type this type corresponds to.
            static const std::shared_ptr<arrow::DataType>& arrow_datatype();

            /// Creates a new array builder with an array of this type.
            static Result<std::shared_ptr<arrow::FloatBuilder>> new_arrow_array_builder(
                arrow::MemoryPool* memory_pool
            );

            /// Fills an arrow array builder with an array of this type.
            static Error fill_arrow_array_builder(
                arrow::FloatBuilder* builder, const Radius* elements, size_t num_elements
            );

            /// Creates a Rerun DataCell from an array of Radius components.
            static Result<rerun::DataCell> to_data_cell(
                const Radius* instances, size_t num_instances
            );
        };
    } // namespace components
} // namespace rerun
