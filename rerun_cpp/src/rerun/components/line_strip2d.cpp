// DO NOT EDIT! This file was auto-generated by crates/re_types_builder/src/codegen/cpp/mod.rs
// Based on "crates/re_types/definitions/rerun/components/line_strip2d.fbs".

#include "line_strip2d.hpp"

#include "../arrow.hpp"
#include "../datatypes/vec2d.hpp"

#include <arrow/builder.h>
#include <arrow/table.h>
#include <arrow/type_fwd.h>

namespace rerun {
    namespace components {
        const char LineStrip2D::NAME[] = "rerun.linestrip2d";

        const std::shared_ptr<arrow::DataType> &LineStrip2D::arrow_datatype() {
            static const auto datatype =
                arrow::list(arrow::field("item", rerun::datatypes::Vec2D::arrow_datatype(), false));
            return datatype;
        }

        Result<std::shared_ptr<arrow::ListBuilder>> LineStrip2D::new_arrow_array_builder(
            arrow::MemoryPool *memory_pool
        ) {
            if (!memory_pool) {
                return Error(ErrorCode::UnexpectedNullArgument, "Memory pool is null.");
            }

            return Result(std::make_shared<arrow::ListBuilder>(
                memory_pool,
                rerun::datatypes::Vec2D::new_arrow_array_builder(memory_pool).value
            ));
        }

        Error LineStrip2D::fill_arrow_array_builder(
            arrow::ListBuilder *builder, const LineStrip2D *elements, size_t num_elements
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

            auto value_builder =
                static_cast<arrow::FixedSizeListBuilder *>(builder->value_builder());
            ARROW_RETURN_NOT_OK(builder->Reserve(static_cast<int64_t>(num_elements)));
            ARROW_RETURN_NOT_OK(value_builder->Reserve(static_cast<int64_t>(num_elements * 2)));

            for (size_t elem_idx = 0; elem_idx < num_elements; elem_idx += 1) {
                const auto &element = elements[elem_idx];
                ARROW_RETURN_NOT_OK(builder->Append());
                if (element.points.data()) {
                    RR_RETURN_NOT_OK(rerun::datatypes::Vec2D::fill_arrow_array_builder(
                        value_builder,
                        element.points.data(),
                        element.points.size()
                    ));
                }
            }

            return Error::ok();
        }

        Result<rerun::DataCell> LineStrip2D::to_data_cell(
            const LineStrip2D *instances, size_t num_instances
        ) {
            // TODO(andreas): Allow configuring the memory pool.
            arrow::MemoryPool *pool = arrow::default_memory_pool();

            auto builder_result = LineStrip2D::new_arrow_array_builder(pool);
            RR_RETURN_NOT_OK(builder_result.error);
            auto builder = std::move(builder_result.value);
            if (instances && num_instances > 0) {
                RR_RETURN_NOT_OK(
                    LineStrip2D::fill_arrow_array_builder(builder.get(), instances, num_instances)
                );
            }
            std::shared_ptr<arrow::Array> array;
            ARROW_RETURN_NOT_OK(builder->Finish(&array));

            auto schema = arrow::schema(
                {arrow::field(LineStrip2D::NAME, LineStrip2D::arrow_datatype(), false)}
            );

            rerun::DataCell cell;
            cell.component_name = LineStrip2D::NAME;
            const auto ipc_result = rerun::ipc_from_table(*arrow::Table::Make(schema, {array}));
            RR_RETURN_NOT_OK(ipc_result.error);
            cell.buffer = std::move(ipc_result.value);

            return cell;
        }
    } // namespace components
} // namespace rerun
