#ifndef GUARD_CONSTANTS_MAPS_H
#define GUARD_CONSTANTS_MAPS_H

#include "map_groups.h"

#define ORDER_ROUTE101								1
#define ORDER_ROUTE102								2
#define ORDER_ROUTE103								3
#define ORDER_ROUTE104								4
#define ORDER_ROUTE105								5
#define ORDER_ROUTE106								6
#define ORDER_ROUTE107								7
#define ORDER_ROUTE108								8
#define ORDER_ROUTE109								9
#define ORDER_ROUTE110								10
#define ORDER_ROUTE111								11
#define ORDER_ROUTE112								12
#define ORDER_ROUTE113								13
#define ORDER_ROUTE114								14
#define ORDER_ROUTE115								15
#define ORDER_ROUTE116								16
#define ORDER_ROUTE117								17
#define ORDER_ROUTE118								18
#define ORDER_ROUTE119								19
#define ORDER_ROUTE120								20
#define ORDER_ROUTE121								21
#define ORDER_ROUTE122								22
#define ORDER_ROUTE123								23
#define ORDER_ROUTE124								24
#define ORDER_ROUTE125								25
#define ORDER_ROUTE126								26
#define ORDER_ROUTE127								27
#define ORDER_ROUTE128								28
#define ORDER_ROUTE129								29
#define ORDER_ROUTE130								30
#define ORDER_ROUTE131								31
#define ORDER_ROUTE132								32
#define ORDER_ROUTE133								33
#define ORDER_ROUTE134								34
#define ORDER_SIDE_AREA								50

#define ORDER_LITTLEROOT_TOWN                       1
#define ORDER_OLDALE_TOWN                           2
#define ORDER_PETALBURG_CITY                        3
#define ORDER_SLATEPORT_CITY                        4
#define ORDER_MAUVILLE_CITY                         5
#define ORDER_RUSTBORO_CITY                         6
#define ORDER_FORTREE_CITY                          7
#define ORDER_LILYCOVE_CITY                         8
#define ORDER_MOSSDEEP_CITY                         9
#define ORDER_SOOTOPOLIS_CITY                       10
#define ORDER_DEWFORD_TOWN                          11
#define ORDER_LAVARIDGE_TOWN                        12
#define ORDER_FALLARBOR_TOWN                        13
#define ORDER_VERDANTURF_TOWN                       14
#define ORDER_PACIFIDLOG_TOWN                       15
#define ORDER_EVER_GRANDE_CITY                      16

#define MAP_NONE (0x7F | (0x7F << 8))
#define MAP_UNDEFINED (0xFF | (0xFF << 8))

#define MAP_GROUP(map) (MAP_##map >> 8)
#define MAP_NUM(map) (MAP_##map & 0xFF)

// These groups are used by pokedex_area_screen.c to find wild
// pokemon locations.
#define MAP_GROUP_OVERWORLD_MONS MAP_GROUP(PETALBURG_CITY)
#define MAP_GROUP_SPECIAL_MONS_1 MAP_GROUP(METEOR_FALLS_1F_1R)
#define MAP_GROUP_SPECIAL_MONS_2 MAP_GROUP(SAFARI_ZONE_NORTHWEST)

#endif  // GUARD_CONSTANTS_MAPS_H
