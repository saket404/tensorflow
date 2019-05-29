/* Copyright 2019 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/
#ifndef TENSORFLOW_CORE_KERNELS_DATA_CONCATENATE_DATASET_OP_H_
#define TENSORFLOW_CORE_KERNELS_DATA_CONCATENATE_DATASET_OP_H_

#include "tensorflow/core/framework/dataset.h"

namespace tensorflow {
namespace data {

class ConcatenateDatasetOp : public BinaryDatasetOpKernel {
 public:
  static constexpr const char kDatasetType[] = "Concatenate";
  static constexpr const char kInputDataset[] = "input_dataset";
  static constexpr const char kAnotherDataset[] = "another_dataset";
  static constexpr const char kOutputTypes[] = "output_types";
  static constexpr const char kOutputShapes[] = "output_shapes";

  explicit ConcatenateDatasetOp(OpKernelConstruction* ctx)
      : BinaryDatasetOpKernel(ctx) {}

 protected:
  void MakeDataset(OpKernelContext* ctx, DatasetBase* input,
                   DatasetBase* to_concatenate, DatasetBase** output) override;

 private:
  class Dataset;
};

}  // namespace data
}  // namespace tensorflow

#endif  // TENSORFLOW_CORE_KERNELS_DATA_CONCATENATE_DATASET_OP_H_