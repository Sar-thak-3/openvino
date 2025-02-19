// Copyright (C) 2018-2023 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include "subgraph_tests/perm_conv_perm_concat.hpp"

#include <vector>

#include "common_test_utils/test_constants.hpp"
namespace {
std::vector<std::array<size_t, 4>> input_shapes{
    {1, 1, 7, 32},
    {1, 1, 8, 16},
};

std::vector<std::array<size_t, 2>> kernel_shapes{
    {1, 3},
    {1, 5},
};

std::vector<size_t> output_channels{
    32,
    64,
};

std::vector<InferenceEngine::Precision> netPrecisions = {
    InferenceEngine::Precision::FP32,
    InferenceEngine::Precision::FP16,
};

std::vector<std::map<std::string, std::string>> configs = {{{"GNA_DEVICE_MODE", "GNA_SW_EXACT"}},
                                                           {{"GNA_DEVICE_MODE", "GNA_SW_FP32"}}};
}  // namespace

namespace SubgraphTestsDefinitions {
INSTANTIATE_TEST_SUITE_P(smoke_basic,
                         PermConvPermConcat,
                         ::testing::Combine(::testing::ValuesIn(netPrecisions),
                                            ::testing::Values(ov::test::utils::DEVICE_GNA),
                                            ::testing::ValuesIn(input_shapes),
                                            ::testing::ValuesIn(kernel_shapes),
                                            ::testing::ValuesIn(output_channels),
                                            ::testing::ValuesIn(configs)),
                         PermConvPermConcat::getTestCaseName);
}  // namespace SubgraphTestsDefinitions
