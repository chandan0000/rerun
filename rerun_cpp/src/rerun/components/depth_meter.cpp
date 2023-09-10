// DO NOT EDIT! This file was auto-generated by crates/re_types_builder/src/codegen/cpp/mod.rs
// Based on "crates/re_types/definitions/rerun/components/depth_meter.fbs".

#include "depth_meter.hpp"

#include "../arrow.hpp"

#include <arrow/builder.h>
#include <arrow/table.h>
#include <arrow/type_fwd.h>

namespace rerun {
    namespace components {
        const char DepthMeter::NAME[] = "rerun.components.DepthMeter";

        const std::shared_ptr<arrow::DataType>& DepthMeter::arrow_datatype() {
            static const auto datatype = arrow::float32();
            return datatype;
        }

        Result<std::shared_ptr<arrow::FloatBuilder>> DepthMeter::new_arrow_array_builder(
            arrow::MemoryPool* memory_pool
        ) {
            if (!memory_pool) {
                return Error(ErrorCode::UnexpectedNullArgument, "Memory pool is null.");
            }

            return Result(std::make_shared<arrow::FloatBuilder>(memory_pool));
        }

        Error DepthMeter::fill_arrow_array_builder(
            arrow::FloatBuilder* builder, const DepthMeter* elements, size_t num_elements
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

            static_assert(sizeof(*elements) == sizeof(elements->value));
            ARROW_RETURN_NOT_OK(
                builder->AppendValues(&elements->value, static_cast<int64_t>(num_elements))
            );

            return Error::ok();
        }

        Result<rerun::DataCell> DepthMeter::to_data_cell(
            const DepthMeter* instances, size_t num_instances
        ) {
            // TODO(andreas): Allow configuring the memory pool.
            arrow::MemoryPool* pool = arrow::default_memory_pool();

            auto builder_result = DepthMeter::new_arrow_array_builder(pool);
            RR_RETURN_NOT_OK(builder_result.error);
            auto builder = std::move(builder_result.value);
            if (instances && num_instances > 0) {
                RR_RETURN_NOT_OK(
                    DepthMeter::fill_arrow_array_builder(builder.get(), instances, num_instances)
                );
            }
            std::shared_ptr<arrow::Array> array;
            ARROW_RETURN_NOT_OK(builder->Finish(&array));

            auto schema =
                arrow::schema({arrow::field(DepthMeter::NAME, DepthMeter::arrow_datatype(), false)}
                );

            rerun::DataCell cell;
            cell.component_name = DepthMeter::NAME;
            const auto ipc_result = rerun::ipc_from_table(*arrow::Table::Make(schema, {array}));
            RR_RETURN_NOT_OK(ipc_result.error);
            cell.buffer = std::move(ipc_result.value);

            return cell;
        }
    } // namespace components
} // namespace rerun
