// DO NOT EDIT! This file was auto-generated by crates/re_types_builder/src/codegen/cpp/mod.rs
// Based on "crates/re_types/definitions/rerun/testing/datatypes/fuzzy.fbs".

#include "affix_fuzzer2.hpp"

#include <arrow/builder.h>
#include <arrow/type_fwd.h>

namespace rerun {
    namespace datatypes {
        const std::shared_ptr<arrow::DataType>& AffixFuzzer2::arrow_datatype() {
            static const auto datatype = arrow::float32();
            return datatype;
        }

        Result<std::shared_ptr<arrow::FloatBuilder>> AffixFuzzer2::new_arrow_array_builder(
            arrow::MemoryPool* memory_pool
        ) {
            if (!memory_pool) {
                return Error(ErrorCode::UnexpectedNullArgument, "Memory pool is null.");
            }

            return Result(std::make_shared<arrow::FloatBuilder>(memory_pool));
        }

        Error AffixFuzzer2::fill_arrow_array_builder(
            arrow::FloatBuilder* builder, const AffixFuzzer2* elements, size_t num_elements
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
                const auto& element = elements[elem_idx];
                if (element.single_float_optional.has_value()) {
                    ARROW_RETURN_NOT_OK(builder->Append(element.single_float_optional.value()));
                } else {
                    ARROW_RETURN_NOT_OK(builder->AppendNull());
                }
            }

            return Error::ok();
        }
    } // namespace datatypes
} // namespace rerun
