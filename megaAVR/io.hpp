/*
 * io.hpp
 *
 * Created: 03/27/2018 01:24:25 PM
 *  Author: user21
 */

#ifndef MEGAAVR_IO_HPP_
#define MEGAAVR_IO_HPP_

#if defined (__AVR_ATmega8U2__)
#  include "spec/m8u2/io.hpp"
#elif defined (__AVR_ATmega16M1__)
#  include "spec/m16m1/io.hpp"
#elif defined (__AVR_ATmega16U2__)
#  include "spec/m16u2/io.hpp"
#elif defined (__AVR_ATmega16U4__)
#  include "spec/m16u4/io.hpp"
#elif defined (__AVR_ATmega32C1__)
#  include "spec/m32c1/io.hpp"
#elif defined (__AVR_ATmega32M1__)
#  include "spec/m32m1/io.hpp"
#elif defined (__AVR_ATmega32U2__)
#  include "spec/m32u2/io.hpp"
#elif defined (__AVR_ATmega32U4__)
#  include "spec/m32u4/io.hpp"
#elif defined (__AVR_ATmega32U6__)
#  include "spec/m32u6/io.hpp"
#elif defined (__AVR_ATmega64C1__)
#  include "spec/m64c1/io.hpp"
#elif defined (__AVR_ATmega64M1__)
#  include "spec/m64m1/io.hpp"
#elif defined (__AVR_ATmega128__)
#  include "spec/m128/io.hpp"
#elif defined (__AVR_ATmega128A__)
#  include "spec/m128a/io.hpp"
#elif defined (__AVR_ATmega1280__)
#  include "spec/m1280/io.hpp"
#elif defined (__AVR_ATmega1281__)
#  include "spec/m1281/io.hpp"
#elif defined (__AVR_ATmega1284__)
#  include "spec/m1284/io.hpp"
#elif defined (__AVR_ATmega1284P__)
#  include "spec/m1284p/io.hpp"
#elif defined (__AVR_ATmega128RFA1__)
#  include "spec/m128rfa1/io.hpp"
#elif defined (__AVR_ATmega1284RFR2__)
#  include "spec/m1284rfr2/io.hpp"
#elif defined (__AVR_ATmega128RFR2__)
#  include "spec/m128rfr2/io.hpp"
#elif defined (__AVR_ATmega2564RFR2__)
#  include "spec/m2564rfr2/io.hpp"
#elif defined (__AVR_ATmega256RFR2__)
#  include "spec/m256rfr2/io.hpp"
#elif defined (__AVR_ATmega2560__)
#  include "spec/m2560/io.hpp"
#elif defined (__AVR_ATmega2561__)
#  include "spec/m2561/io.hpp"
#elif defined (__AVR_ATmega644RFR2__)
#  include "spec/m644rfr2/io.hpp"
#elif defined (__AVR_ATmega64RFR2__)
#  include "spec/m64rfr2/io.hpp"
#elif defined (__AVR_ATmega64__)
#  include "spec/m64/io.hpp"
#elif defined (__AVR_ATmega64A__)
#  include "spec/m64a/io.hpp"
#elif defined (__AVR_ATmega640__)
#  include "spec/m640/io.hpp"
#elif defined (__AVR_ATmega644__)
#  include "spec/m644/io.hpp"
#elif defined (__AVR_ATmega644A__)
#  include "spec/m644a/io.hpp"
#elif defined (__AVR_ATmega644P__)
#  include "spec/m644p/io.hpp"
#elif defined (__AVR_ATmega644PA__)
#  include "spec/m644pa/io.hpp"
#elif defined (__AVR_ATmega645__)
#  include "spec/m645/io.hpp"
#elif defined (__AVR_ATmega645A__)
#  include "spec/m645a/io.hpp"
#elif defined (__AVR_ATmega645P__)
#  include "spec/m645p/io.hpp"
#elif defined (__AVR_ATmega6450__)
#  include "spec/m6450/io.hpp"
#elif defined (__AVR_ATmega6450A__)
#  include "spec/m6450a/io.hpp"
#elif defined (__AVR_ATmega6450P__)
#  include "spec/m6450p/io.hpp"
#elif defined (__AVR_ATmega649__)
#  include "spec/m649/io.hpp"
#elif defined (__AVR_ATmega649A__)
#  include "spec/m649a/io.hpp"
#elif defined (__AVR_ATmega6490__)
#  include "spec/m6490/io.hpp"
#elif defined (__AVR_ATmega6490A__)
#  include "spec/m6490a/io.hpp"
#elif defined (__AVR_ATmega6490P__)
#  include "spec/m6490p/io.hpp"
#elif defined (__AVR_ATmega649P__)
#  include "spec/m649p/io.hpp"
#elif defined (__AVR_ATmega64HVE__)
#  include "spec/m64hve/io.hpp"
#elif defined (__AVR_ATmega64HVE2__)
#  include "spec/m64hve2/io.hpp"
#elif defined (__AVR_ATmega103__)
#  include "spec/m103/io.hpp"
#elif defined (__AVR_ATmega32__)
#  include "spec/m32/io.hpp"
#elif defined (__AVR_ATmega32A__)
#  include "spec/m32a/io.hpp"
#elif defined (__AVR_ATmega323__)
#  include "spec/m323/io.hpp"
#elif defined (__AVR_ATmega324P__)
#  include "spec/m324p/io.hpp"
#elif defined (__AVR_ATmega324A__)
#  include "spec/m324a/io.hpp"
#elif defined (__AVR_ATmega324PA__)
#  include "spec/m324pa/io.hpp"
#elif defined (__AVR_ATmega325__)
#  include "spec/m325/io.hpp"
#elif defined (__AVR_ATmega325A__)
#  include "spec/m325a/io.hpp"
#elif defined (__AVR_ATmega325P__)
#  include "spec/m325p/io.hpp"
#elif defined (__AVR_ATmega325PA__)
#  include "spec/m325pa/io.hpp"
#elif defined (__AVR_ATmega3250__)
#  include "spec/m3250/io.hpp"
#elif defined (__AVR_ATmega3250A__)
#  include "spec/m3250a/io.hpp"
#elif defined (__AVR_ATmega3250P__)
#  include "spec/m3250p/io.hpp"
#elif defined (__AVR_ATmega3250PA__)
#  include "spec/m3250pa/io.hpp"
#elif defined (__AVR_ATmega328P__)
#  include "spec/m328p/io.hpp"
#elif defined (__AVR_ATmega328__)
#  include "spec/m328/io.hpp"
#elif defined (__AVR_ATmega329__)
#  include "spec/m329/io.hpp"
#elif defined (__AVR_ATmega329A__)
#  include "spec/m329a/io.hpp"
#elif defined (__AVR_ATmega329P__)
#  include "spec/m329p/io.hpp"
#elif defined (__AVR_ATmega329PA__)
#  include "spec/m329pa/io.hpp"
#elif defined (__AVR_ATmega3290PA__)
#  include "spec/m3290pa/io.hpp"
#elif defined (__AVR_ATmega3290__)
#  include "spec/m3290/io.hpp"
#elif defined (__AVR_ATmega3290A__)
#  include "spec/m3290a/io.hpp"
#elif defined (__AVR_ATmega3290P__)
#  include "spec/m3290/io.hpp"
#elif defined (__AVR_ATmega32HVB__)
#  include "spec/m32hvb/io.hpp"
#elif defined (__AVR_ATmega32HVBREVB__)
#  include "spec/m32hvbrevb/io.hpp"
#elif defined (__AVR_ATmega406__)
#  include "spec/m406/io.hpp"
#elif defined (__AVR_ATmega16__)
#  include "spec/m16/io.hpp"
#elif defined (__AVR_ATmega16A__)
#  include "spec/m16a/io.hpp"
#elif defined (__AVR_ATmega161__)
#  include "spec/m161/io.hpp"
#elif defined (__AVR_ATmega162__)
#  include "spec/m162/io.hpp"
#elif defined (__AVR_ATmega163__)
#  include "spec/m163/io.hpp"
#elif defined (__AVR_ATmega164P__)
#  include "spec/m164p/io.hpp"
#elif defined (__AVR_ATmega164A__)
#  include "spec/m164a/io.hpp"
#elif defined (__AVR_ATmega164PA__)
#  include "spec/m164pa/io.hpp"
#elif defined (__AVR_ATmega165__)
#  include "spec/m165/io.hpp"
#elif defined (__AVR_ATmega165A__)
#  include "spec/m165a/io.hpp"
#elif defined (__AVR_ATmega165P__)
#  include "spec/m165p/io.hpp"
#elif defined (__AVR_ATmega165PA__)
#  include "spec/m165pa/io.hpp"
#elif defined (__AVR_ATmega168__)
#  include "spec/m168/io.hpp"
#elif defined (__AVR_ATmega168A__)
#  include "spec/m168a/io.hpp"
#elif defined (__AVR_ATmega168P__)
#  include "spec/m168p/io.hpp"
#elif defined (__AVR_ATmega168PA__)
#  include "spec/m168pa/io.hpp"
#elif defined (__AVR_ATmega168PB__)
#  include "spec/m168pb/io.hpp"
#elif defined (__AVR_ATmega169__)
#  include "spec/m169/io.hpp"
#elif defined (__AVR_ATmega169A__)
#  include "spec/m169a/io.hpp"
#elif defined (__AVR_ATmega169P__)
#  include "spec/m169p/io.hpp"
#elif defined (__AVR_ATmega169PA__)
#  include "spec/m169pa/io.hpp"
#elif defined (__AVR_ATmega8HVA__)
#  include "spec/m8hva/io.hpp"
#elif defined (__AVR_ATmega16HVA__)
#  include "spec/m16hva/io.hpp"
#elif defined (__AVR_ATmega16HVA2__)
#  include "spec/m16hva2/io.hpp"
#elif defined (__AVR_ATmega16HVB__)
#  include "spec/m16hvb/io.hpp"
#elif defined (__AVR_ATmega16HVBREVB__)
#  include "spec/m16hvbrevb/io.hpp"
#elif defined (__AVR_ATmega8__)
#  include "spec/m8/io.hpp"
#elif defined (__AVR_ATmega8A__)
#  include "spec/m8a/io.hpp"
#elif defined (__AVR_ATmega48__)
#  include "spec/m48/io.hpp"
#elif defined (__AVR_ATmega48A__)
#  include "spec/m48a/io.hpp"
#elif defined (__AVR_ATmega48PA__)
#  include "spec/m48pa/io.hpp"
#elif defined (__AVR_ATmega48PB__)
#  include "spec/m48pb/io.hpp"
#elif defined (__AVR_ATmega48P__)
#  include "spec/m48p/io.hpp"
#elif defined (__AVR_ATmega88__)
#  include "spec/m88/io.hpp"
#elif defined (__AVR_ATmega88A__)
#  include "spec/m88a/io.hpp"
#elif defined (__AVR_ATmega88P__)
#  include "spec/m88p/io.hpp"
#elif defined (__AVR_ATmega88PA__)
#  include "spec/m88pa/io.hpp"
#elif defined (__AVR_ATmega88PB__)
#  include "spec/m88pb/io.hpp"
#elif defined (__AVR_ATmega8515__)
#  include "spec/m8515/io.hpp"
#elif defined (__AVR_ATmega8535__)
#  include "spec/m8535/io.hpp"
#else
#error "device type not defined"
#endif

namespace megaAVR {
// preprocessor trick on selecting the proper namespace
using namespace

#if defined (__AVR_ATmega8U2__)
m8u2
#elif defined (__AVR_ATmega16M1__)
m16m1
#elif defined (__AVR_ATmega16U2__)
m16u2
#elif defined (__AVR_ATmega16U4__)
m16u4
#elif defined (__AVR_ATmega32C1__)
m32c1
#elif defined (__AVR_ATmega32M1__)
m32m1
#elif defined (__AVR_ATmega32U2__)
m32u2
#elif defined (__AVR_ATmega32U4__)
m32u4
#elif defined (__AVR_ATmega32U6__)
m32u6
#elif defined (__AVR_ATmega64C1__)
m64c1
#elif defined (__AVR_ATmega64M1__)
m64m1
#elif defined (__AVR_ATmega128__)
m128
#elif defined (__AVR_ATmega128A__)
m128a
#elif defined (__AVR_ATmega1280__)
m1280
#elif defined (__AVR_ATmega1281__)
m1281
#elif defined (__AVR_ATmega1284__)
m1284
#elif defined (__AVR_ATmega1284P__)
m1284p
#elif defined (__AVR_ATmega128RFA1__)
m128rfa1
#elif defined (__AVR_ATmega1284RFR2__)
m1284rfr2
#elif defined (__AVR_ATmega128RFR2__)
m128rfr2
#elif defined (__AVR_ATmega2564RFR2__)
m2564rfr2
#elif defined (__AVR_ATmega256RFR2__)
m256rfr2
#elif defined (__AVR_ATmega2560__)
m2560
#elif defined (__AVR_ATmega2561__)
m2561
#elif defined (__AVR_ATmega644RFR2__)
m644rfr2
#elif defined (__AVR_ATmega64RFR2__)
m64rfr2
#elif defined (__AVR_ATmega64__)
m64
#elif defined (__AVR_ATmega64A__)
m64a
#elif defined (__AVR_ATmega640__)
m640
#elif defined (__AVR_ATmega644__)
m644
#elif defined (__AVR_ATmega644A__)
m644a
#elif defined (__AVR_ATmega644P__)
m644p
#elif defined (__AVR_ATmega644PA__)
m644pa
#elif defined (__AVR_ATmega645__)
m645
#elif defined (__AVR_ATmega645A__)
m645a
#elif defined (__AVR_ATmega645P__)
m645p
#elif defined (__AVR_ATmega6450__)
m6450
#elif defined (__AVR_ATmega6450A__)
m6450a
#elif defined (__AVR_ATmega6450P__)
m6450p
#elif defined (__AVR_ATmega649__)
m649
#elif defined (__AVR_ATmega649A__)
m649a
#elif defined (__AVR_ATmega6490__)
m6490
#elif defined (__AVR_ATmega6490A__)
m6490a
#elif defined (__AVR_ATmega6490P__)
m6490p
#elif defined (__AVR_ATmega649P__)
m649p
#elif defined (__AVR_ATmega64HVE__)
m64hve
#elif defined (__AVR_ATmega64HVE2__)
m64hve2
#elif defined (__AVR_ATmega103__)
m103
#elif defined (__AVR_ATmega32__)
m32
#elif defined (__AVR_ATmega32A__)
m32a
#elif defined (__AVR_ATmega323__)
m323
#elif defined (__AVR_ATmega324P__)
m324p
#elif defined (__AVR_ATmega324A__)
m324a
#elif defined (__AVR_ATmega324PA__)
m324pa
#elif defined (__AVR_ATmega325__)
m325
#elif defined (__AVR_ATmega325A__)
m325a
#elif defined (__AVR_ATmega325P__)
m325p
#elif defined (__AVR_ATmega325PA__)
m325pa
#elif defined (__AVR_ATmega3250__)
m3250
#elif defined (__AVR_ATmega3250A__)
m3250a
#elif defined (__AVR_ATmega3250P__)
m3250p
#elif defined (__AVR_ATmega3250PA__)
m3250pa
#elif defined (__AVR_ATmega328P__)
m328p
#elif defined (__AVR_ATmega328__)
m328
#elif defined (__AVR_ATmega329__)
m329
#elif defined (__AVR_ATmega329A__)
m329a
#elif defined (__AVR_ATmega329P__)
m329p
#elif defined (__AVR_ATmega329PA__)
m329pa
#elif defined (__AVR_ATmega3290PA__)
m3290pa
#elif defined (__AVR_ATmega3290__)
m3290
#elif defined (__AVR_ATmega3290A__)
m3290a
#elif defined (__AVR_ATmega3290P__)
m3290
#elif defined (__AVR_ATmega32HVB__)
m32hvb
#elif defined (__AVR_ATmega32HVBREVB__)
m32hvbrevb
#elif defined (__AVR_ATmega406__)
m406
#elif defined (__AVR_ATmega16__)
m16
#elif defined (__AVR_ATmega16A__)
m16a
#elif defined (__AVR_ATmega161__)
m161
#elif defined (__AVR_ATmega162__)
m162
#elif defined (__AVR_ATmega163__)
m163
#elif defined (__AVR_ATmega164P__)
m164p
#elif defined (__AVR_ATmega164A__)
m164a
#elif defined (__AVR_ATmega164PA__)
m164pa
#elif defined (__AVR_ATmega165__)
m165
#elif defined (__AVR_ATmega165A__)
m165a
#elif defined (__AVR_ATmega165P__)
m165p
#elif defined (__AVR_ATmega165PA__)
m165pa
#elif defined (__AVR_ATmega168__)
m168
#elif defined (__AVR_ATmega168A__)
m168a
#elif defined (__AVR_ATmega168P__)
m168p
#elif defined (__AVR_ATmega168PA__)
m168pa
#elif defined (__AVR_ATmega168PB__)
m168pb
#elif defined (__AVR_ATmega169__)
m169
#elif defined (__AVR_ATmega169A__)
m169a
#elif defined (__AVR_ATmega169P__)
m169p
#elif defined (__AVR_ATmega169PA__)
m169pa
#elif defined (__AVR_ATmega8HVA__)
m8hva
#elif defined (__AVR_ATmega16HVA__)
m16hva
#elif defined (__AVR_ATmega16HVA2__)
m16hva2
#elif defined (__AVR_ATmega16HVB__)
m16hvb
#elif defined (__AVR_ATmega16HVBREVB__)
m16hvbrevb
#elif defined (__AVR_ATmega8__)
m8
#elif defined (__AVR_ATmega8A__)
m8a
#elif defined (__AVR_ATmega48__)
m48
#elif defined (__AVR_ATmega48A__)
m48a
#elif defined (__AVR_ATmega48PA__)
m48pa
#elif defined (__AVR_ATmega48PB__)
m48pb
#elif defined (__AVR_ATmega48P__)
m48p
#elif defined (__AVR_ATmega88__)
m88
#elif defined (__AVR_ATmega88A__)
m88a
#elif defined (__AVR_ATmega88P__)
m88p
#elif defined (__AVR_ATmega88PA__)
m88pa
#elif defined (__AVR_ATmega88PB__)
m88pb
#elif defined (__AVR_ATmega8515__)
m8515
#elif defined (__AVR_ATmega8535__)
m8535
#else
    #error "megaAVR io namespace cannot be selected"
#endif
; // using namespace /* preprocessor-based namespace selection */

} // namespace megaAVR

#endif /* MEGAAVR_IO_HPP_ */
