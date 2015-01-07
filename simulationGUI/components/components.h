
#ifndef COMPONENTS_H
#define COMPONENTS_H

// This header file includes the header files of all components.

#include "component.h"

#include "ground.h"
#include "resistor.h"
#include "capacitor.h"
#include "inductor.h"
#include "sparamfile.h"
#include "equation.h"
#include "volt_dc.h"
#include "ampere_dc.h"
#include "volt_ac.h"
#include "ampere_ac.h"
#include "source_ac.h"
#include "param_sweep.h"
#include "iprobe.h"
#include "vprobe.h"
#include "spicefile.h"
#include "libcomp.h"
#include "transformer.h"
#include "tline.h"
#include "logical_nand.h"
#include "logical_nor.h"
#include "logical_and.h"
#include "logical_or.h"
#include "switch.h"

// external simulation components

// Verilog-A dynamicaly loaded component
#include "vacomponent.h"

#endif
