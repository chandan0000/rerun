// DO NOT EDIT! This file was auto-generated by crates/re_types_builder/src/codegen/cpp/mod.rs
// Based on "crates/re_types/definitions/rerun/datatypes/scale3d.fbs".

#include "scale3d.hpp"

#include "vec3d.hpp"

#include <arrow/builder.h>
#include <arrow/type_fwd.h>

namespace rerun {
    namespace datatypes {
        const std::shared_ptr<arrow::DataType> &Scale3D::arrow_datatype() {
            static const auto datatype = arrow::dense_union({
                arrow::field("_null_markers", arrow::null(), true, nullptr),
                arrow::field("ThreeD", rerun::datatypes::Vec3D::arrow_datatype(), false),
                arrow::field("Uniform", arrow::float32(), false),
            });
            return datatype;
        }

        Result<std::shared_ptr<arrow::DenseUnionBuilder>> Scale3D::new_arrow_array_builder(
            arrow::MemoryPool *memory_pool
        ) {
            if (!memory_pool) {
                return Error(ErrorCode::UnexpectedNullArgument, "Memory pool is null.");
            }

            return Result(std::make_shared<arrow::DenseUnionBuilder>(
                memory_pool,
                std::vector<std::shared_ptr<arrow::ArrayBuilder>>({
                    std::make_shared<arrow::NullBuilder>(memory_pool),
                    rerun::datatypes::Vec3D::new_arrow_array_builder(memory_pool).value,
                    std::make_shared<arrow::FloatBuilder>(memory_pool),
                }),
                arrow_datatype()
            ));
        }

        Error Scale3D::fill_arrow_array_builder(
            arrow::DenseUnionBuilder *builder, const Scale3D *elements, size_t num_elements
        ) {
            if (!builder) {
                return Error(ErrorCode::UnexpectedNullArgument, "Passed array builder is null.");
            }
            if (!elements) {
                return Error(
                    ErrorCode::UnexpectedNullArgument,
                    "Cannot serialize null pointer to arrow array."
                );
            }

            ARROW_RETURN_NOT_OK(builder->Reserve(static_cast<int64_t>(num_elements)));
            for (size_t elem_idx = 0; elem_idx < num_elements; elem_idx += 1) {
                const auto &union_instance = elements[elem_idx];
                ARROW_RETURN_NOT_OK(builder->Append(static_cast<int8_t>(union_instance._tag)));

                auto variant_index = static_cast<int>(union_instance._tag);
                auto variant_builder_untyped = builder->child_builder(variant_index).get();

                switch (union_instance._tag) {
                    case detail::Scale3DTag::NONE: {
                        ARROW_RETURN_NOT_OK(variant_builder_untyped->AppendNull());
                        break;
                    }
                    case detail::Scale3DTag::ThreeD: {
                        auto variant_builder =
                            static_cast<arrow::FixedSizeListBuilder *>(variant_builder_untyped);
                        RR_RETURN_NOT_OK(rerun::datatypes::Vec3D::fill_arrow_array_builder(
                            variant_builder,
                            &union_instance._data.three_d,
                            1
                        ));
                        break;
                    }
                    case detail::Scale3DTag::Uniform: {
                        auto variant_builder =
                            static_cast<arrow::FloatBuilder *>(variant_builder_untyped);
                        ARROW_RETURN_NOT_OK(variant_builder->Append(union_instance._data.uniform));
                        break;
                    }
                }
            }

            return Error::ok();
        }
    } // namespace datatypes
} // namespace rerun
