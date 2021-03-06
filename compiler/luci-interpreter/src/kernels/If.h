/*
 * Copyright (c) 2020 Samsung Electronics Co., Ltd. All Rights Reserved
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef LUCI_INTERPRETER_KERNELS_IF_H
#define LUCI_INTERPRETER_KERNELS_IF_H

#include "core/Kernel.h"
#include "core/RuntimeGraph.h"

namespace luci_interpreter
{
namespace kernels
{

class If : public Kernel
{
public:
  If(const Tensor *cond, std::vector<const Tensor *> inputs, std::vector<Tensor *> outputs,
     RuntimeGraph *then_graph, RuntimeGraph *else_graph);

  std::vector<const Tensor *> getInputTensors() const override
  {
    std::vector<const Tensor *> input_tensors{_cond};
    input_tensors.insert(input_tensors.cend(), _inputs.cbegin(), _inputs.cend());
    return input_tensors;
  }

  std::vector<Tensor *> getOutputTensors() const override { return _outputs; }

  void configure() override;
  void execute() const override;

private:
  const Tensor *const _cond;
  const std::vector<const Tensor *> _inputs;
  const std::vector<Tensor *> _outputs;
  RuntimeGraph *const _then_graph;
  RuntimeGraph *const _else_graph;
};

} // namespace kernels
} // namespace luci_interpreter

#endif // LUCI_INTERPRETER_KERNELS_IF_H
