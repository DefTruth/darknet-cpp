#ifndef REORG_LAYER_H
#define REORG_LAYER_H

#include "cuda.h"
#include "image.h"
#include "layer.h"
#include "network.h"
#ifdef __cplusplus
extern "C"
{
#endif
  layer make_reorg_layer(int batch,
                         int w,
                         int h,
                         int c,
                         int stride,
                         int reverse,
                         int flatten,
                         int extra);
  void resize_reorg_layer(layer *l, int w, int h);
  void forward_reorg_layer(const layer l, network net);
  void backward_reorg_layer(const layer l, network net);

#ifdef DKGPU
  void forward_reorg_layer_gpu(layer l, network net);
  void backward_reorg_layer_gpu(layer l, network net);
#endif
#ifdef __cplusplus
}
#endif
#endif
