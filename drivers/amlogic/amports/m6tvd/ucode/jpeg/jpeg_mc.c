/*
 * AMLOGIC HW JPEG decoder driver.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the named License,
 * or any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA
 *
 * Author:  Tim Yao <timyao@amlogic.com>
 *
 */

#include <linux/types.h>

const u32 jpegdec_mc[] __attribute__((aligned(8))) = {
0x06801801,0x06800000,0x0d000001,0x07400040,0x0680c000,0x060c2900,
0x06800000,0x060c0800,0x080c0002,0x06bfbf80,0x06030400,0x0649c000,
0x07c01140,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00400000,0x00000000,0x0c780000,0x00000000,0x00000000,0x00000000,
0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
0x00000000,0x00000000,0x0c780800,0x00000000,0x0cc00000,0x00400000,
0x0cc00000,0x00400000,0x0cc00000,0x00400000,0x0cc00000,0x00400000,
0x0cc00000,0x00400000,0x0cc00000,0x00400000,0x0cc00000,0x00400000,
0x0c780500,0x064c0007,0x0cc00000,0x00400000,0x0cc00000,0x00400000,
0x0cc00000,0x00400000,0x00000000,0x00000000,0x0cc00000,0x00400000,
0x00000000,0x00000000,0x0cc00000,0x00400000,0x0cc00000,0x00400000,
0x0c7fff00,0x080c0000,0x0be10807,0x00400000,0x0bef0047,0x0c7ffdc0,
0x09c09147,0x060c0009,0x0c012780,0x0680020f,0x040001cf,0x0aaf7fc7,
0x0aa1f607,0x0aa0f647,0x0c780c40,0x00000000,0x0c792100,0x00000000,
0x0c784100,0x06800048,0x07c00c08,0x06bfffc8,0x07c01048,0x06800008,
0x07c01008,0x0c783f40,0x00000000,0x07800c49,0x0ba79049,0x00000000,
0x0c012200,0x0680020f,0x0400020f,0x07c00c88,0x06800007,0x06c00047,
0x060e0207,0x06800007,0x06c00047,0x060e0207,0x0be283c8,0x06800808,
0x0c011f00,0x0680040f,0x040001cf,0x0d07ff48,0x060e0207,0x04441249,
0x0c7ffb00,0x07c00c49,0x0c011d00,0x0680040f,0x040001cf,0x0d07ff48,
0x060e0307,0x04441249,0x0c7ff900,0x07c00c49,0x0aa0c009,0x0c00db80,
0x04000449,0x0c783640,0x00000000,0x07800c08,0x0aaf4008,0x048f8207,
0x046d0208,0x0c508d40,0x00000000,0x046da207,0x0c5076c0,0x00000000,
0x0c011780,0x0680040f,0x0400020f,0x0b2c8088,0x04402208,0x07c00c48,
0x046c0207,0x0c500700,0x046db207,0x0c57f280,0x046dd207,0x0c500380,
0x046c4207,0x0c503180,0x046c2207,0x0c5070c0,0x046e1207,0x0c504980,
0x00000000,0x07800c48,0x0aa0c008,0x0c00d300,0x04000448,0x0c782dc0,
0x00000000,0x07800c49,0x0aa0c089,0x0c7ff5c0,0x00000000,0x0c011040,
0x0680040f,0x0400020f,0x07c01048,0x0c782b40,0x07c01008,0x07800c49,
0x0c010e80,0x0680020f,0x040001cf,0x0c010dc0,0x0680040f,0x0400020f,
0x0c010d00,0x0680040f,0x040001cf,0x0c010c40,0x0680020f,0x040000cf,
0x07c01203,0x054010c3,0x0609c003,0x0609c107,0x0609c208,0x07c004c7,
0x07c00508,0x08007401,0x0649c00a,0x0a2fc04a,0x00000000,0x0c010140,
0x0902328a,0x0649c40a,0x07c00b0a,0x0649c50a,0x07c00b4a,0x040071c7,
0x058031c7,0x060c0907,0x07c00607,0x07c002c7,0x04007208,0x05803208,
0x07c00308,0x0649120a,0x07c0128a,0x0649130a,0x07c012ca,0x0649140a,
0x07c0130a,0x0649150a,0x07c0134a,0x090281c3,0x0aa240c7,0x0aa14047,
0x00000000,0x0809c004,0x08007401,0x0c780000,0x0aa18249,0x0c781bc0,
0x00000000,0x0aa343c9,0x0c781b00,0x00000000,0x0c010000,0x0680020f,
0x040001cf,0x0c00ff40,0x0680010f,0x040001cf,0x06800047,0x07c00cc7,
0x0c780280,0x07c00d07,0x0c00fd80,0x0680020f,0x040001cf,0x07c00cc7,
0x0c00fc80,0x0680010f,0x040001cf,0x07c00d07,0x0609c507,0x0aa2c047,
0x06800049,0x0a600087,0x06800089,0x078002c8,0x04001208,0x05801208,
0x07c002c8,0x05401208,0x0c780240,0x07c00608,0x07801288,0x05401208,
0x07c01288,0x078012c8,0x05401208,0x04001208,0x07c012c8,0x07801207,
0x0aa1c0c7,0x00000000,0x0c00f600,0x0680010f,0x040001cf,0x0c780140,
0x06800047,0x0c00f4c0,0x0680010f,0x040001cf,0x07c00d47,0x0aa20047,
0x0a600087,0x07800308,0x04001208,0x05801208,0x07c00308,0x0c780240,
0x05401249,0x07801308,0x05401208,0x07c01308,0x07801348,0x05401208,
0x04001208,0x07c01348,0x07c00409,0x0c00efc0,0x0680020f,0x040001cf,
0x07c00d87,0x07801207,0x0aa0c0c7,0x0c780a40,0x00000000,0x0c00edc0,
0x0680020f,0x040001cf,0x07c00dc7,0x0c00ecc0,0x0680010f,0x040001cf,
0x07c00e07,0x0c00ebc0,0x0680010f,0x040001cf,0x07c00e47,0x0c00eac0,
0x0680020f,0x040001cf,0x07c00e87,0x0c00e9c0,0x0680020f,0x040001cf,
0x07c00ec7,0x0c00e8c0,0x0680010f,0x040001cf,0x07c00f07,0x0c00e7c0,
0x0680010f,0x040001cf,0x07c00f47,0x0c00e6c0,0x0680020f,0x040001cf,
0x07c00f87,0x0c7801c0,0x0aa10009,0x00000000,0x0c00a5c0,0x04000449,
0x0c780080,0x00000000,0x080c0002,0x0c7fb940,0x00000000,0x0c7817c0,
0x00000000,0x07800c49,0x0baf4449,0x00000000,0x0c00e200,0x0680020f,
0x0400020f,0x04401249,0x0a20bc08,0x0c780900,0x0480f208,0x0aa0c008,
0x0aa14048,0x0c780000,0x06801804,0x0c780100,0x06801c06,0x06802404,
0x06802806,0x06800005,0x06800007,0x0680040a,0x07400187,0x04001186,
0x0c00dd00,0x0680020f,0x0400020f,0x02007207,0x02005205,0x05401145,
0x0340b285,0x058022cb,0x0740010b,0x0d07fd4a,0x04001104,0x04410249,
0x0b83a1c9,0x024091c9,0x0c00d980,0x0680020f,0x0400020f,0x07400188,
0x0d07ff07,0x04001186,0x0c7ff580,0x0480f208,0x0aa10008,0x0aa18048,
0x0c780000,0x00000000,0x06800004,0x0c780100,0x06803406,0x06800044,
0x06805806,0x060c2104,0x06800005,0x06800007,0x0680040a,0x0c00d440,
0x0680020f,0x0400020f,0x02007207,0x0ba0c08a,0x00000000,0x060c2607,
0x02005205,0x05401145,0x0340b285,0x058022cb,0x0ba0c08a,0x00000000,
0x060c220b,0x0d07fc8a,0x00000000,0x04410249,0x0b8121c9,0x024091c9,
0x0b220047,0x05801107,0x0c00cf00,0x0680040f,0x0400020f,0x07400188,
0x0d07ff04,0x04001186,0x0a21c047,0x00000000,0x0c00cd00,0x0680020f,
0x0400020f,0x05408208,0x07400188,0x0c7fe940,0x0aa0c009,0x0c008c00,
0x04000449,0x0c7fe6c0,0x00000000,0x0c7fb780,0x00000000,0x07801189,
0x0a6f4009,0x07801149,0x0a2ec049,0x07800c49,0x0bae4109,0x0c00c840,
0x0680040f,0x040001cf,0x04402249,0x06915e08,0x0a4f3207,0x07c00c49,
0x069a5988,0x0c00c640,0x0680040f,0x040001cf,0x04402249,0x0a4ec207,
0x07c00c49,0x0c00c4c0,0x0680040f,0x040001cf,0x04402249,0x0680000a,
0x06925248,0x0c00c340,0x0680040f,0x040001cf,0x0400228a,0x0a8031c8,
0x06800047,0x06800007,0x07c011c7,0x0c00c140,0x0680040f,0x040001cf,
0x0c00c1c0,0x0400228a,0x02407287,0x0aa1c007,0x044011c7,0x0c00bf40,
0x0680020f,0x0400020f,0x0c7ffec0,0x0400128a,0x078011c8,0x0c00bdc0,
0x0680040f,0x040001cf,0x0aa14008,0x0400228a,0x048ff207,0x058081c7,
0x095081c8,0x05403207,0x054021c7,0x02007207,0x0aa1c007,0x044011c7,
0x0c00ba80,0x0680020f,0x0400020f,0x0c7ffec0,0x0400128a,0x0c00ba80,
0x00000000,0x0b804287,0x0b403247,0x0a618007,0x02407287,0x02409289,
0x07c00c49,0x0c7fa480,0x00000000,0x0aa1c007,0x044011c7,0x0c00b640,
0x0680020f,0x0400020f,0x0c7ffec0,0x0400128a,0x078011c8,0x0c00b4c0,
0x0680040f,0x040001cf,0x0aa14008,0x0400228a,0x048ff207,0x058081c7,
0x095081c8,0x040002c7,0x0680c007,0x0b4ea1cb,0x0aaa400b,0x044012cb,
0x078011c8,0x0c00b140,0x0680040f,0x040001cf,0x0aa14008,0x0400228a,
0x048ff207,0x058081c7,0x095081c8,0x06808048,0x0a813207,0x00000000,
0x0c00ae80,0x0680040f,0x040001cf,0x0c00adc0,0x0680040f,0x040001cf,
0x0c00ad00,0x0680040f,0x040001cf,0x0c00ac40,0x0680040f,0x040001cf,
0x0c00ab80,0x0680040f,0x040001cf,0x0c7ff8c0,0x0400a28a,0x0c00aa40,
0x0680040f,0x040001cf,0x0c00a980,0x0680040f,0x040001cf,0x0c00a8c0,
0x0680040f,0x040001cf,0x0400628a,0x0c00a900,0x00000000,0x0b404247,
0x0ac031ca,0x0c7800c0,0x02407287,0x0c7fee80,0x0aa1c007,0x044011c7,
0x0c00a580,0x0680020f,0x0400020f,0x0c7ffec0,0x00000000,0x06800048,
0x07c01188,0x06800008,0x0c7fbf80,0x07c00c08,0x0809c100,0x06bfffc7,
0x0609c207,0x0c7fbe40,0x00000000,0x0c7fbdc0,0x080c0800,0x080c0840,
0x0c00a100,0x0680040f,0x0400020f,0x0b2e8088,0x04402208,0x07c00c48,
0x07801144,0x0a228044,0x0649c004,0x0a222004,0x07801184,0x0be18044,
0x00000000,0x0809c006,0x08007401,0x0c780000,0x00000000,0x0649c004,
0x091c2104,0x0a644044,0x07800d84,0x0a2183c4,0x06800804,0x0d000104,
0x080e0200,0x0c780140,0x06800005,0x0d000004,0x080e0300,0x06800045,
0x07800e84,0x09404105,0x07c00e84,0x07800f84,0x09404105,0x07c00f84,
0x07800c49,0x0c0097c0,0x0680020f,0x0400020f,0x04401249,0x07c00108,
0x07801206,0x0a806206,0x06800146,0x0809c004,0x08007401,0x0c780000,
0x00000000,0x0c0094c0,0x0680020f,0x040001cf,0x07800d8a,0x07800cc4,
0x0a808107,0x07800405,0x07800e8a,0x07800dc4,0x0a804107,0x06810045,
0x06814045,0x07800f8a,0x0958414a,0x07400185,0x04001186,0x0c0090c0,
0x0680020f,0x040001cf,0x07400187,0x04402249,0x0d07fac8,0x04001186,
0x0fc101c0,0x0c008ec0,0x0680020f,0x040001cf,0x04403249,0x0aa0c009,
0x0c004e40,0x04000449,0x080c0a10,0x080c2c01,0x06800004,0x07c00004,
0x07c00044,0x0609c404,0x080c2a00,0x06800004,0x098047c4,0x060c2d04,
0x098043c4,0x060c2f04,0x06800004,0x07c00084,0x07800084,0x07800146,
0x0aa1c004,0x07800185,0x078001c6,0x0aa10044,0x07800205,0x07800246,
0x07800285,0x09184106,0x0aa0c004,0x0680050a,0x0680070a,0x09104106,
0x0ba0c104,0x060c2a04,0x04403104,0x07c00484,0x09003106,0x07c00444,
0x09084105,0x0aa0c004,0x06801806,0x06802406,0x07c00386,0x09004105,
0x060c2104,0x0aa0c004,0x06803404,0x06805804,0x07c003c4,0x06800004,
0x07c00344,0x07800384,0x064c2a07,0x04004144,0x07000146,0x0b82c187,
0x04006144,0x07000146,0x0b823187,0x04007144,0x07000146,0x0b838187,
0x068001c6,0x04008144,0x07000146,0x0b834187,0x06800206,0x04009144,
0x07000146,0x0b830187,0x06800246,0x0400a144,0x07000146,0x0b82c187,
0x06800286,0x0400b144,0x07000146,0x0b828187,0x068002c6,0x0400c144,
0x07000146,0x0b824187,0x06800306,0x0400d144,0x07000146,0x0b820187,
0x06800346,0x0400e144,0x07000146,0x0b81c187,0x06800386,0x0c780680,
0x068003c6,0x04005144,0x07000146,0x0b816187,0x06800146,0x0c780500,
0x06800186,0x04002144,0x07000146,0x0b807187,0x04003144,0x07000146,
0x0b80d187,0x068000c6,0x0c7802c0,0x06800106,0x04001144,0x07000146,
0x0b407187,0x06800086,0x07000106,0x0b404187,0x06800046,0x0c780080,
0x06800006,0x04001206,0x0c007080,0x040003c8,0x040001cf,0x0aa20006,
0x02005184,0x04401145,0x07000145,0x068003c8,0x02408188,0x03805205,
0x02407147,0x04010104,0x02006184,0x07000186,0x020061c6,0x04010104,
0x02006184,0x07000186,0x064c2404,0x0a20c3c4,0x0c7fff80,0x00000000,
0x060c2306,0x060e000a,0x078003c9,0x064c2503,0x0a2fe003,0x0a211003,
0x09005103,0x0c7802c0,0x00000000,0x09127203,0x02008209,0x07000208,
0x060c2708,0x0c0067c0,0x040003c4,0x040001cf,0x0c7ffcc0,0x080c2440,
0x080c2480,0x078005c4,0x0be14044,0x00000000,0x04c01104,0x0c002840,
0x07c005c4,0x06800045,0x07800007,0x07801288,0x02407207,0x07800048,
0x07801304,0x02408108,0x07800484,0x0a670004,0x07800d06,0x0aa18046,
0x07800346,0x054011c7,0x04801186,0x02c07187,0x0c780240,0x07800d46,
0x0aa3c046,0x07800346,0x05401208,0x04801186,0x09461146,0x02c08188,
0x0c780240,0x07800d46,0x0aa1c046,0x00000000,0x05401208,0x07800346,
0x09021186,0x09461146,0x02c08188,0x0649c306,0x09104186,0x0c780340,
0x094c4146,0x0649c306,0x07800d0a,0x0a60c04a,0x09142246,0x04001249,
0x09502149,0x07800d4a,0x0a60c04a,0x09102246,0x04001249,0x094c2149,
0x0aa0c007,0x0c780140,0x09482144,0x09805045,0x0c780080,0x09482144,
0x06491e06,0x0befc086,0x00000000,0x0649c006,0x0a20d006,0x00000000,
0x04807208,0x06091d08,0x07800006,0x07801288,0x0b805206,0x078012c8,
0x0ac03206,0x0c780140,0x00000000,0x06bfffc6,0x0c7800c0,0x06091c06,
0x06091c07,0x06091b05,0x07800606,0x0aa14004,0x07800d08,0x0aa0c048,
0x00000000,0x05801186,0x040011c7,0x0b809187,0x09805285,0x09c05045,
0x09c05085,0x06491e06,0x0befc086,0x00000000,0x06091c07,0x06091b05,
0x07800344,0x04001104,0x07800445,0x0b403144,0x0c7fcc40,0x07c00344,
0x07800084,0x04001104,0x07800105,0x0b403144,0x0c7fc280,0x07c00084,
0x07800004,0x04001104,0x078002c5,0x0b818144,0x07c00004,0x06800004,
0x07c00004,0x07800044,0x04001104,0x07800046,0x07c00044,0x0609c404,
0x07801307,0x0b80e1c6,0x07800547,0x07800d46,0x02007187,0x07c00547,
0x07800305,0x0b411144,0x07801345,0x0ac0f144,0x00000000,0x0ba10207,
0x0c0012c0,0x06800004,0x07c00544,0x07801004,0x0aa0c004,0x0aa10044,
0x04401104,0x0c7fb9c0,0x07c01004,0x07801044,0x0c7f5f00,0x07c01004,
0x078005c7,0x0a20c187,0x06800184,0x06800104,0x07c005c4,0x0c000e80,
0x00000000,0x064c2404,0x0befc3c4,0x00000000,0x0803ffa5,0x0c783b40,
0x00000000,0x0aa1c011,0x00000000,0x0c003ec0,0x0680020f,0x0400020f,
0x0d07ff51,0x00000000,0x0cc00000,0x00000000,0x07800a45,0x07800a07,
0x09610147,0x06092d05,0x06802907,0x06092107,0x08091600,0x08091700,
0x0649c107,0x0649c308,0x091c2208,0x03407207,0x06091407,0x078012c7,
0x07801288,0x02407207,0x040011c7,0x054031c7,0x07800d08,0x04401208,
0x03407207,0x06091207,0x07801347,0x07801308,0x02407207,0x040011c7,
0x054031c7,0x07800d48,0x04401208,0x03407207,0x06091307,0x0649c308,
0x09102208,0x03807207,0x06091507,0x06a04007,0x0649c308,0x09004208,
0x02c07207,0x0cc00000,0x06091107,0x06491e07,0x0befc087,0x00000000,
0x0649c006,0x0a241006,0x00000000,0x0809c501,0x00000000,0x00000000,
0x00000000,0x00000000,0x00000000,0x00000000,0x0649c506,0x0aae4046,
0x00000000,0x078005c6,0x04806186,0x0cc00000,0x07c005c6,0x078005c6,
0x04806186,0x0aa5c006,0x0aa58186,0x06b00007,0x06091107,0x06800005,
0x0a614005,0x07800808,0x07800849,0x0c780140,0x0780088a,0x078008c8,
0x07800909,0x0780094a,0x09610289,0x06801387,0x05403185,0x02007187,
0x06091f07,0x06092008,0x0609200a,0x04001145,0x0bac00c5,0x00000000,
0x07800a45,0x07800a07,0x09610147,0x06092c05,0x078009c5,0x07800987,
0x09610147,0x06092d05,0x06801287,0x06092107,0x06800005,0x07800b47,
0x06091607,0x07800b07,0x06091707,0x0649c107,0x06091407,0x0649c308,
0x091c2208,0x03407207,0x0aa0c005,0x06091207,0x058011c7,0x040071c7,
0x058031c7,0x06092307,0x07801347,0x07801308,0x02407207,0x040011c7,
0x054031c7,0x07800d48,0x04401208,0x03407207,0x0649c308,0x09102208,
0x03807207,0x06091307,0x0649c207,0x06091507,0x06a6c147,0x0649c009,
0x090a1249,0x05001249,0x095811c9,0x0649c308,0x09084208,0x094841c8,
0x06091107,0x08091c00,0x07800589,0x0649c308,0x09102208,0x0780054a,
0x06800047,0x03407207,0x044011c7,0x0200a1ca,0x0380a20a,0x0aa14005,
0x02008289,0x05801249,0x0400128a,0x0580128a,0x07801207,0x044011c7,
0x0b8031c5,0x00000000,0x07c00588,0x078005c7,0x048061c7,0x0aa54187,
0x069001c8,0x0aa20007,0x068001c8,0x04402249,0x0400228a,0x0aa28087,
0x068021c8,0x0c780340,0x069021c8,0x07801207,0x044011c7,0x0a4091c5,
0x06800087,0x0c7801c0,0x07c005c7,0x07801207,0x044011c7,0x0a4031c5,
0x06800087,0x07c005c7,0x06091d09,0x0609240a,0x09482205,0x0649c307,
0x091841c7,0x09504207,0x06092208,0x00000000,0x06491e07,0x0befc087,
0x00000000,0x06b00007,0x06091107,0x05401185,0x06801087,0x02007187,
0x06091f07,0x06492007,0x06492007,0x06492009,0x0a618005,0x05810209,
0x07c00807,0x07c00848,0x0c780140,0x07c00889,0x07c008c7,0x07c00908,
0x07c00949,0x04001145,0x07801206,0x0a803185,0x0c7fe3c0,0x00000000,
0x0cc00000,0x00000000,0x06492d00,0x05810040,0x09010000,0x07c00981,
0x07c009c0,0x06492c00,0x05810040,0x09010000,0x07c00a01,0x07c00a40,
0x0cc00000,0x00000000,0x08007401,0x0c7ed9c0,0x0809c002,0x00000000,
0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
0x064c4708,0x0b2e2008,0x00000000,0x0c7ffd80,0x00000000,0x0c0000c0,
0x0680040f,0x0400020f,0x064c4710,0x0b2fe010,0x00000000,0x0cc00000,
0x0f8003cf,0x078011c8,0x0aa2c048,0x0400428a,0x0c07fe00,0x0680040f,
0x040001cf,0x054101c7,0x0c07fd00,0x0680040f,0x0400020f,0x0cc00000,
0x094101c8,0x0c07fbc0,0x0680020f,0x040001cf,0x0c07fb00,0x0680020f,
0x0400020f,0x095081c8,0x0c07fa00,0x0680020f,0x0400020f,0x096081c8,
0x0c07f900,0x0680020f,0x0400020f,0x0cc00000,0x00000000,0x06011f28,
0x06411f28,0x0a6fc028,0x00000000,0x0cc00000,0x00000000};
