// Copyright (C) 2018-2022 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//
#pragma once

#include <gtest/gtest.h>

#include <memory>

#include "openvino/runtime/core.hpp"
#include "openvino/runtime/iplugin.hpp"

namespace ov {
namespace hetero {
namespace tests {

class HeteroTests : public ::testing::Test {
public:
    ov::Core core;

    void SetUp() override;

    std::shared_ptr<ov::Model> create_model_with_subtract();
    std::shared_ptr<ov::Model> create_model_with_subtract_reshape();
    std::shared_ptr<ov::Model> create_model_with_subtract_reshape_relu();
    std::shared_ptr<ov::Model> create_model_with_reshape();
    ov::Tensor create_and_fill_tensor(const ov::element::Type& type, const ov::Shape& shape);

private:
    template <class T>
    ov::Tensor create_tensor(const ov::element::Type& type, const ov::Shape& shape) {
        ov::Tensor tensor(type, shape);
        T* data = tensor.data<T>();
        for (size_t i = 0; i < tensor.get_size(); i++) {
            data[i] = static_cast<T>(i);
        }
        return tensor;
    }
    std::vector<std::shared_ptr<ov::IPlugin>> m_mock_plugins;
    std::shared_ptr<void> m_so;

    template <typename T>
    void reg_plugin_type(const std::string& device_name);

    void reg_plugin(std::shared_ptr<ov::IPlugin>& plugin);
};

}  // namespace tests
}  // namespace hetero
}  // namespace ov
