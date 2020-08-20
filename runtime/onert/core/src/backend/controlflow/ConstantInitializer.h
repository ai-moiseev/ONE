/*
 * Copyright (c) 2020 Samsung Electronics Co., Ltd. All Rights Reserved
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __ONERT_COMPILER_CONTROLFLOW_CONSTANT_INITIALIZER_H__
#define __ONERT_COMPILER_CONTROLFLOW_CONSTANT_INITIALIZER_H__

#include "TensorRegistry.h"

#include <backend/IConstantInitializer.h>
#include <ir/Operands.h>

namespace onert
{
namespace backend
{
namespace controlflow
{

class ConstantInitializer : public IConstantInitializer
{
public:
  ConstantInitializer(const ir::Operands &operands,
                      const std::shared_ptr<ITensorRegistry> &tensor_reg)
      : IConstantInitializer{operands}, _tensor_reg{tensor_reg}
  {
  }

private:
  std::shared_ptr<ITensorRegistry> tensor_registry() const override { return _tensor_reg; }

private:
  std::shared_ptr<ITensorRegistry> _tensor_reg;
};

} // namespace controlflow
} // namespace backend
} // namespace onert

#endif // __ONERT_COMPILER_CONTROLFLOW_CONSTANT_INITIALIZER_H__
