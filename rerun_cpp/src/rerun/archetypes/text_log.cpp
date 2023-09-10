// DO NOT EDIT! This file was auto-generated by crates/re_types_builder/src/codegen/cpp/mod.rs
// Based on "crates/re_types/definitions/rerun/archetypes/text_log.fbs".

#include "text_log.hpp"

#include "../indicator_component.hpp"

namespace rerun {
    namespace archetypes {
        const char TextLog::INDICATOR_COMPONENT_NAME[] = "rerun.components.TextLogIndicator";

        std::vector<AnonymousComponentBatch> TextLog::as_component_batches() const {
            std::vector<AnonymousComponentBatch> comp_batches;
            comp_batches.reserve(3);

            comp_batches.emplace_back(body);
            if (level.has_value()) {
                comp_batches.emplace_back(level.value());
            }
            if (color.has_value()) {
                comp_batches.emplace_back(color.value());
            }
            comp_batches.emplace_back(
                ComponentBatch<components::IndicatorComponent<TextLog::INDICATOR_COMPONENT_NAME>>(
                    nullptr,
                    num_instances()
                )
            );

            return comp_batches;
        }
    } // namespace archetypes
} // namespace rerun
