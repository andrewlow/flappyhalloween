/*******************************************************************************
 * Copyright (c) 2015 Andrew Low.
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v1.0
 * which accompanies this distribution, and is available at
 * http://www.eclipse.org/legal/epl-v10.html
 *
 * Contributors:
 *    Andrew Low - initial implementation
 *******************************************************************************/
 
#include "flight.h"

const unsigned char flight1[] {
  48,  50,  51,  53,  54,  55,  56,  57,
  58,  59,  59,  59,  59,  58,  58,  57,
  55,  54,  53,  51,  49,  47,  44,  42,
  39,  37,  34,  31,  29,  26,  23,  20,
  18,  15,  13,  11,  9,  7,  5,  4,
  3,  2,  1,  1,  0,  1,  1,  1,
  2,  3,  5,  6,  8,  10,  12,  14,
  16,  19,  21,  23,  26,  28,  31,  33,
  36,  38,  40,  42,  44,  45,  47,  48,
  49,  50,  51,  52,  52,  52,  52,  52,
  51,  51,  50,  49,  48,  47,  46,  45,
  43,  42,  41,  40,  38,  37,  36,  35,
  34,  33,  32,  31,  31,  30,  30,  30,
  30,  30,  30,  30,  31,  31,  32,  32,
  33,  34,  34,  35,  36,  37,  37,  38,
  38,  39,  39,  39,  39,  39,  39,  38,
  38,  37,  36,  35,  34,  33,  32,  30,
  29,  27,  26,  24,  22,  21,  19,  17,
  16,  14,  13,  11,  10,  9,  8,  8,
  7,  7,  7,  7,  7,  8,  9,  10,
  11,  13,  14,  16,  18,  21,  23,  25,
  28,  31,  33,  36,  39,  41,  44,  47,
  49,  51,  54,  56,  57,  59,  60,  62,
  63,  63,  64,  64,  64,  63,  63,  62,
  61,  60,  58,  56,  54,  52,  50,  48,
  45,  43,  40,  38,  35,  33,  30,  28,
  25,  23,  21,  19,  17,  16,  14,  13,
  12,  11,  10,  10,  10,  10,  10,  11,
  11,  12,  13,  14,  15,  16,  17,  19,
  20,  22,  23,  25,  26,  27,  29,  30,
  31,  32,  33,  34,  34,  35,  35,  36,
  36,  36,  36,  35,  35,  35,  34,  34,
  33,  32,  32,  31,  30,  30,  29,  28,
  28,  28,  27,  27,  27,  27,  27,  28,
  28,  29,  29,  30,  31,  32,  34,  35,
  36,  38,  39,  41,  42,  44,  45,  47,
  48,  50,  51,  52,  53,  54,  54,  55,
  55,  55,  55,  55,  54,  54,  53,  51,
  50,  48,  47,  45,  42,  40,  38,  35,
  33,  30,  28,  25,  22,  20,  17,  15,
  12,  10,  8,  7,  5,  3,  2,  1,
  1,  0,  0,  0,  0,  1,  2,  3,
  4,  6,  8,  10,  12,  14,  16,  19,
  21,  24,  27,  29,  32,  35,  37,  40,
  42,  44,  46,  48,  50,  51,  53,  54,
  55,  55,  56,  56,  56,  56,  55,  55,
  54,  53,  52,  51,  50,  48,  47,  45,
  43,  42,  40,  39,  37,  36,  34,  33,
  32,  30,  29,  29,  28,  27,  27,  27,
  26,  26,  26,  27,  27,  27,  28,  28,
  29,  30,  30,  31,  32,  32,  33,  33,
  34,  34,  35,  35,  35,  35,  35,  35,
  34,  34,  33,  32,  31,  30,  29,  28,
  27,  26,  24,  23,  21,  20,  19,  17,
  16,  15,  14,  13,  12,  12,  11,  11,
  11,  11,  11,  12,  12,  13,  14,  16,
  17,  19,  21,  23,  25,  27,  29,  32,
  34,  37,  39,  42,  44,  47,              // offset 462
  
  48,  50,  51,  53,  54,  55,  56,  57,    // 144 additional values, allow us to wrap
  58,  59,  59,  59,  59,  58,  58,  57,
  55,  54,  53,  51,  49,  47,  44,  42,
  39,  37,  34,  31,  29,  26,  23,  20,
  18,  15,  13,  11,  9,  7,  5,  4,
  3,  2,  1,  1,  0,  1,  1,  1,
  2,  3,  5,  6,  8,  10,  12,  14,
  16,  19,  21,  23,  26,  28,  31,  33,
  36,  38,  40,  42,  44,  45,  47,  48,
  49,  50,  51,  52,  52,  52,  52,  52,
  51,  51,  50,  49,  48,  47,  46,  45,
  43,  42,  41,  40,  38,  37,  36,  35,
  34,  33,  32,  31,  31,  30,  30,  30,
  30,  30,  30,  30,  31,  31,  32,  32,
  33,  34,  34,  35,  36,  37,  37,  38,
  38,  39,  39,  39,  39,  39,  39,  38,
  38,  37,  36,  35,  34,  33,  32,  30,
  29,  27,  26,  24,  22,  21,  19,  17 };


