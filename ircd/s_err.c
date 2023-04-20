/************************************************************************
 *   IRC - Internet Relay Chat, ircd/s_err.c
 *   Copyright (C) 1992 Darren Reed
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 1, or (at your option)
 *   any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#ifndef lint
static const volatile char rcsid[] = "@(#)$Id: s_err.c,v 1.71 2010/08/12 16:24:31 bif Exp $";
#endif

#include "os.h"
#include "s_defines.h"
#define S_ERR_C
#include "s_externs.h"
#undef S_ERR_C

char *	replies[] = {
/* 000  */ (char *)NULL,
/* 001 RPL_WELCOME  */	":%s 001 %s :Welcome to the Internet Relay Network %s",
/* 002 RPL_YOURHOST */	":%s 002 %s :Your host is %s, running version %s",
/* 003 RPL_CREATED */	":%s 003 %s :This server was created %s",
/* 004 RPL_MYINFO */	":%s 004 %s %s %s aHoOirw abeiIklmnoOpqrRstv",
/* 005 RPL_ISUPPORT */  ":%s 005 %s %s :are supported by this server",
/* 006 */ (char *)NULL,
/* 007 */ (char *)NULL,
/* 008 */ (char *)NULL,
/* 009 */ (char *)NULL,
/* 010 RPL_BOUNCE */	":%s 010 %s %s %d :Please use this Server/Port instead",
/* 011 */ (char *)NULL,
/* 012 */ (char *)NULL,
/* 013 */ (char *)NULL,
/* 014 */ (char *)NULL,
/* 015 RPL_MAP */	":%s 015 %s :%s",
/* 016 */ (char *)NULL,
/* 017 RPL_MAPEND */	":%s 017 %s :End of MAP",
/* 018 RPL_MAPSTART */	":%s 018 %s :%s",
/* 019 */ (char *)NULL,
/* 020 RPL_HELLO */	":%s 020 * :%s",
/* 021 */ (char *)NULL,
/* 022 */ (char *)NULL,
/* 023 */ (char *)NULL,
/* 024 */ (char *)NULL,
/* 025 */ (char *)NULL,
/* 026 */ (char *)NULL,
/* 027 */ (char *)NULL,
/* 028 */ (char *)NULL,
/* 029 */ (char *)NULL,
/* 030 */ (char *)NULL,
/* 031 */ (char *)NULL,
/* 032 */ (char *)NULL,
/* 033 */ (char *)NULL,
/* 034 */ (char *)NULL,
/* 035 */ (char *)NULL,
/* 036 */ (char *)NULL,
/* 037 */ (char *)NULL,
/* 038 */ (char *)NULL,
/* 039 */ (char *)NULL,
/* 040 */ (char *)NULL,
/* 041 */ (char *)NULL,
/* 042 RPL_YOURID */	":%s 042 %s %s :your unique ID",
/* 043 RPL_SAVENICK */	":%s 043 %s %s :nickname collision, forcing nick change to your unique ID.",
/* 044 */ (char *)NULL,
/* 045 */ (char *)NULL,
/* 046 */ (char *)NULL,
/* 047 */ (char *)NULL,
/* 048 */ (char *)NULL,
/* 049 */ (char *)NULL,
/* 050 */ (char *)NULL,
/* 051 */ (char *)NULL,
/* 052 */ (char *)NULL,
/* 053 */ (char *)NULL,
/* 054 */ (char *)NULL,
/* 055 */ (char *)NULL,
/* 056 */ (char *)NULL,
/* 057 */ (char *)NULL,
/* 058 */ (char *)NULL,
/* 059 */ (char *)NULL,
/* 060 */ (char *)NULL,
/* 061 */ (char *)NULL,
/* 062 */ (char *)NULL,
/* 063 */ (char *)NULL,
/* 064 */ (char *)NULL,
/* 065 */ (char *)NULL,
/* 066 */ (char *)NULL,
/* 067 */ (char *)NULL,
/* 068 */ (char *)NULL,
/* 069 */ (char *)NULL,
/* 070 */ (char *)NULL,
/* 071 */ (char *)NULL,
/* 072 */ (char *)NULL,
/* 073 */ (char *)NULL,
/* 074 */ (char *)NULL,
/* 075 */ (char *)NULL,
/* 076 */ (char *)NULL,
/* 077 */ (char *)NULL,
/* 078 */ (char *)NULL,
/* 079 */ (char *)NULL,
/* 080 */ (char *)NULL,
/* 081 */ (char *)NULL,
/* 082 */ (char *)NULL,
/* 083 */ (char *)NULL,
/* 084 */ (char *)NULL,
/* 085 */ (char *)NULL,
/* 086 */ (char *)NULL,
/* 087 */ (char *)NULL,
/* 088 */ (char *)NULL,
/* 089 */ (char *)NULL,
/* 090 */ (char *)NULL,
/* 091 */ (char *)NULL,
/* 092 */ (char *)NULL,
/* 093 */ (char *)NULL,
/* 094 */ (char *)NULL,
/* 095 */ (char *)NULL,
/* 096 */ (char *)NULL,
/* 097 */ (char *)NULL,
/* 098 */ (char *)NULL,
/* 099 */ (char *)NULL,
/* 100 */ (char *)NULL,
/* 101 */ (char *)NULL,
/* 102 */ (char *)NULL,
/* 103 */ (char *)NULL,
/* 104 */ (char *)NULL,
/* 105 */ (char *)NULL,
/* 106 */ (char *)NULL,
/* 107 */ (char *)NULL,
/* 108 */ (char *)NULL,
/* 109 */ (char *)NULL,
/* 110 */ (char *)NULL,
/* 111 */ (char *)NULL,
/* 112 */ (char *)NULL,
/* 113 */ (char *)NULL,
/* 114 */ (char *)NULL,
/* 115 */ (char *)NULL,
/* 116 */ (char *)NULL,
/* 117 */ (char *)NULL,
/* 118 */ (char *)NULL,
/* 119 */ (char *)NULL,
/* 120 */ (char *)NULL,
/* 121 */ (char *)NULL,
/* 122 */ (char *)NULL,
/* 123 */ (char *)NULL,
/* 124 */ (char *)NULL,
/* 125 */ (char *)NULL,
/* 126 */ (char *)NULL,
/* 127 */ (char *)NULL,
/* 128 */ (char *)NULL,
/* 129 */ (char *)NULL,
/* 130 */ (char *)NULL,
/* 131 */ (char *)NULL,
/* 132 */ (char *)NULL,
/* 133 */ (char *)NULL,
/* 134 */ (char *)NULL,
/* 135 */ (char *)NULL,
/* 136 */ (char *)NULL,
/* 137 */ (char *)NULL,
/* 138 */ (char *)NULL,
/* 139 */ (char *)NULL,
/* 140 */ (char *)NULL,
/* 141 */ (char *)NULL,
/* 142 */ (char *)NULL,
/* 143 */ (char *)NULL,
/* 144 */ (char *)NULL,
/* 145 */ (char *)NULL,
/* 146 */ (char *)NULL,
/* 147 */ (char *)NULL,
/* 148 */ (char *)NULL,
/* 149 */ (char *)NULL,
/* 150 */ (char *)NULL,
/* 151 */ (char *)NULL,
/* 152 */ (char *)NULL,
/* 153 */ (char *)NULL,
/* 154 */ (char *)NULL,
/* 155 */ (char *)NULL,
/* 156 */ (char *)NULL,
/* 157 */ (char *)NULL,
/* 158 */ (char *)NULL,
/* 159 */ (char *)NULL,
/* 160 */ (char *)NULL,
/* 161 */ (char *)NULL,
/* 162 */ (char *)NULL,
/* 163 */ (char *)NULL,
/* 164 */ (char *)NULL,
/* 165 */ (char *)NULL,
/* 166 */ (char *)NULL,
/* 167 */ (char *)NULL,
/* 168 */ (char *)NULL,
/* 169 */ (char *)NULL,
/* 170 */ (char *)NULL,
/* 171 */ (char *)NULL,
/* 172 */ (char *)NULL,
/* 173 */ (char *)NULL,
/* 174 */ (char *)NULL,
/* 175 */ (char *)NULL,
/* 176 */ (char *)NULL,
/* 177 */ (char *)NULL,
/* 178 */ (char *)NULL,
/* 179 */ (char *)NULL,
/* 180 */ (char *)NULL,
/* 181 */ (char *)NULL,
/* 182 */ (char *)NULL,
/* 183 */ (char *)NULL,
/* 184 */ (char *)NULL,
/* 185 */ (char *)NULL,
/* 186 */ (char *)NULL,
/* 187 */ (char *)NULL,
/* 188 */ (char *)NULL,
/* 189 */ (char *)NULL,
/* 190 */ (char *)NULL,
/* 191 */ (char *)NULL,
/* 192 */ (char *)NULL,
/* 193 */ (char *)NULL,
/* 194 */ (char *)NULL,
/* 195 */ (char *)NULL,
/* 196 */ (char *)NULL,
/* 197 */ (char *)NULL,
/* 198 */ (char *)NULL,
/* 199 */ (char *)NULL,
/* 200 RPL_TRACELINK */	":%s 200 %s Link %s%s %s %s V%X%s %d %d %d",
/* 201 RPL_TRACECONNECTING */	":%s 201 %s Try. %d %s",
/* 202 RPL_TRACEHANDSHAKE */	":%s 202 %s H.S. %d %s",
/* 203 RPL_TRACEUNKNOWN */	":%s 203 %s ???? %d %s",
/* 204 RPL_TRACEOPERATOR */	":%s 204 %s Oper %d %s",
/* 205 RPL_TRACEUSER */	":%s 205 %s User %d %s",
/* 206 RPL_TRACESERVER */	":%s 206 %s Serv %d %dS %dC %s %s!%s@%s V%X%s",
/* 207 RPL_TRACESERVICE */	":%s 207 %s Service %d %s 0x%X 0x%X",
/* 208 RPL_TRACENEWTYPE */	":%s 208 %s <newtype> 0 %s",
/* 209 */ NULL,
/* 210 */ NULL,
/* 211 RPL_STATSLINKINFO */	(char *)NULL,
/* 212 RPL_STATSCOMMANDS */	":%s 212 %s %s %u %u %u %u %u %u %u %u %u %u %u %u %u %u %u %u %u %u %u %u",
/* 213 RPL_STATSCLINE */	":%s 213 %s %c %s %s %s %d %d",
/* 214 RPL_STATSNLINE */	":%s 214 %s %c %s %s %s %d %d",
/* 215 RPL_STATSILINE */	":%s 215 %s %c %s %s %s %d %d %s",
/* 216 RPL_STATSKLINE */	":%s 216 %s %c %s %s %s %d %d",
/* 217 RPL_STATSQLINE */	":%s 217 %s %c %s %s %s %d %d",
/* 218 RPL_STATSYLINE */	":%s 218 %s %c %d %d %d %d %d.%d %d.%d %d.%d %d%s",
/* 219 RPL_ENDOFSTATS */	":%s 219 %s %c :End of STATS report",
/* 220 */ (char *)NULL,
/* 221 RPL_UMODEIS */	":%s 221 %s %s",
/* 222 */ (char *)NULL,
/* 223 */ (char *)NULL,
/* 224 */ (char *)NULL,
/* 225 */ (char *)NULL,
/* 226 */ (char *)NULL,
/* 227 */ (char *)NULL,
/* 228 */ (char *)NULL,
/* 229 */ (char *)NULL,
/* 230 */ (char *)NULL,
/* 231 RPL_SERVICEINFO */	(char *)NULL,
/* 232 RPL_ENDOFSERVICES */	(char *)NULL,
/* 233 RPL_SERVICE */	(char *)NULL,
/* 234 RPL_SERVLIST */	":%s 234 %s %s %s %s 0x%X 0x%X %d :%s",
/* 235 RPL_SERVLISTEND */	":%s 235 %s %s %d :End of service listing",
/* 236 */ (char *)NULL,
/* 237 */ (char *)NULL,
/* 238 */ (char *)NULL,
/* 239 */ (char *)NULL,
/* 240 RPL_STATSVLINE */	":%s 240 %s %c %s %s %s %d %d",
/* 241 RPL_STATSLLINE */	":%s 241 %s %c %s %s %s %d %d",
/* 242 RPL_STATSUPTIME */	":%s 242 %s :Server Up %d days, %d:%02d:%02d",
/* 243 RPL_STATSOLINE */	":%s 243 %s %c %s %s %s %d %d %s",
/* 244 RPL_STATSHLINE */	":%s 244 %s %c %s %s %s %d %d", 
/* 245 RPL_STATSSLINE */	":%s 245 %s %c %s %s %s 0x%X %d", 
/* 246 RPL_STATSPING */	":%s 246 %s %s %d %d %d %d",
/* 247 RPL_STATSBLINE */	":%s 247 %s %c %s %s %s %d %d",
/* 248 RPL_STATSDEFINE */	(char *)NULL,
/* 249 RPL_STATSDEBUG */	(char *)NULL,
/* 250 RPL_STATSDLINE */	":%s 250 %s %c %s %s %s %d %d",
/* 251 RPL_LUSERCLIENT */	":%s 251 %s :There are %d users and %d services on %d servers",
/* 252 RPL_LUSEROP */	":%s 252 %s %d :operators online",
/* 253 RPL_LUSERUNKNOWN */	":%s 253 %s %d :unknown connections",
/* 254 RPL_LUSERCHANNELS */	":%s 254 %s %d :channels formed",
/* 255 RPL_LUSERME */	":%s 255 %s :I have %d users, %d services and %d servers",
/* 256 RPL_ADMINME */	":%s 256 %s :Administrative info about %s",
/* 257 RPL_ADMINLOC1 */	":%s 257 %s :%s",
/* 258 RPL_ADMINLOC2 */	":%s 258 %s :%s",
/* 259 RPL_ADMINEMAIL */	":%s 259 %s :%s",
/* 260 */ (char *)NULL,
/* 261 */ (char *)NULL,
/* 262 RPL_TRACEEND */	":%s 262 %s %s %s.%s :End of TRACE",
/* 263 RPL_TRYAGAIN */	":%s 263 %s %s :Please wait a while and try again.",
/* 264 */ (char *)NULL,
/* 265 RPL_LOCALUSERS */	":%s 265 %s %d %d :Current local users %d, max %d",
/* 266 RPL_GLOBALUSERS */	":%s 266 %s %d %d :Current global users %d, max %d",
/* 267 */ (char *)NULL,
/* 268 */ (char *)NULL,
/* 269 */ (char *)NULL,
/* 270 */ (char *)NULL,
/* 271 */ (char *)NULL,
/* 272 */ (char *)NULL,
/* 273 */ (char *)NULL,
/* 274 */ (char *)NULL,
/* 275 */ (char *)NULL,
/* 276 */ (char *)NULL,
/* 277 */ (char *)NULL,
/* 278 */ (char *)NULL,
/* 279 */ (char *)NULL,
/* 280 */ (char *)NULL,
/* 281 */ (char *)NULL,
/* 282 */ (char *)NULL,
/* 283 */ (char *)NULL,
/* 284 */ (char *)NULL,
/* 285 */ (char *)NULL,
/* 286 */ (char *)NULL,
/* 287 */ (char *)NULL,
/* 288 */ (char *)NULL,
/* 289 */ (char *)NULL,
/* 290 */ (char *)NULL,
/* 291 */ (char *)NULL,
/* 292 */ (char *)NULL,
/* 293 */ (char *)NULL,
/* 294 */ (char *)NULL,
/* 295 */ (char *)NULL,
/* 296 */ (char *)NULL,
/* 297 */ (char *)NULL,
/* 298 */ (char *)NULL,
/* 299 */ (char *)NULL,
/* 300 RPL_NONE */	(char *)NULL,
/* 301 RPL_AWAY */	":%s 301 %s %s :%s",
/* 302 RPL_USERHOST */	":%s 302 %s :",
/* 303 RPL_ISON */	":%s 303 %s :",
/* 304 RPL_TEXT */	(char *)NULL,
/* 305 RPL_UNAWAY */	":%s 305 %s :You are no longer marked as being away",
/* 306 RPL_NOWAWAY */	":%s 306 %s :You have been marked as being away",
/* 307 */ (char *)NULL,
/* 308 */ (char *)NULL,
/* 309 */ (char *)NULL,
/* 310 */ (char *)NULL,
/* 311 RPL_WHOISUSER */	":%s 311 %s %s %s %s * :%s",
/* 312 RPL_WHOISSERVER */	":%s 312 %s %s %s :%s",
/* 313 RPL_WHOISOPERATOR */	":%s 313 %s %s :is an IRC Operator",
/* 314 RPL_WHOWASUSER */	":%s 314 %s %s %s %s * :%s",
/* 315 RPL_ENDOFWHO */	":%s 315 %s %s :End of WHO list.",
/* 316 RPL_WHOISCHANOP */	(char *)NULL,
#ifdef WHOIS_SIGNON_TIME
/* 317 RPL_WHOISIDLE */	":%s 317 %s %s %ld %ld :seconds idle, signon time",
#else
/* 317 RPL_WHOISIDLE */	":%s 317 %s %s %ld :seconds idle",
#endif
/* 318 RPL_ENDOFWHOIS */	":%s 318 %s %s :End of WHOIS list.",
/* 319 RPL_WHOISCHANNELS */	":%s 319 %s %s :%s",
#ifdef RPL_WHOISEXTRA
/* 320 RPL_WHOISEXTRA */    ":%s 320 %s %s :%s", /* catch-all extra WHOIS information reply - non-standard use of 320 -- mh 20200111 */
#else
#if defined RPL_WHOISCLOAKED || defined RPL_WHOISTLS
#ifdef RPL_WHOISCLOAKED
/* 320 RPL_WHOISCLOAKED */  ":%s 320 %s %s :%s", /* client is cloaked/spoofed - non-standard use of 320 -- mh 20191230 */
#else
/* 320 RPL_WHOISTLS */      ":%s 320 %s %s :%s", /* client is connected with SSL/TLS - non-standard use of 320 -- mh 2020-04-27 */
#endif
#else
/* 320 */ (char *)NULL,
#endif
#endif
/* 321 RPL_LISTSTART */	":%s 321 %s Channel :Users  Name",
/* 322 RPL_LIST */	":%s 322 %s %s %d :%s",
/* 323 RPL_LISTEND */	":%s 323 %s :End of LIST",
/* 324 RPL_CHANNELMODEIS */	":%s 324 %s %s %s %s",
/* 325 RPL_UNIQOPIS */	":%s 325 %s %s %s",
/* 326 */ (char *)NULL,
/* 327 */ (char *)NULL,
/* 328 */ (char *)NULL,
/* 329 */ (char *)NULL,
#ifdef SASL_WHOISLOGGEDIN
/* 330 RPL_WHOISLOGGEDIN */	":%s 330 %s %s %s :is logged in as",
#else
/* 330 RPL_WHOISLOGGEDIN */	(char *)NULL,
#endif
/* 331 RPL_NOTOPIC */	":%s 331 %s %s :No topic is set.",
/* 332 RPL_TOPIC */	":%s 332 %s %s :%s",
/* 333 RPL_TOPIC_WHO_TIME */	":%s 333 %s %s %s %lu",
/* 334 */ (char *)NULL,
/* 335 */ (char *)NULL,
/* 336 */ (char *)NULL,
/* 337 */ (char *)NULL,
/* 338 */ (char *)NULL,
/* 339 */ (char *)NULL,
/* 340 */ (char *)NULL,
/* 341 RPL_INVITING */	":%s 341 %s %s %s",
/* 342 RPL_SUMMONING */	":%s 342 %s %s :User summoned to irc",
/* 343 */ (char *)NULL,
/* 344 RPL_REOPLIST */	":%s 344 %s %s %s!%s@%s",
/* 345 RPL_ENDOFREOPLIST */	":%s 345 %s %s :End of Channel Reop List",
/* 346 RPL_INVITELIST */	":%s 346 %s %s %s!%s@%s",
/* 347 RPL_ENDOFINVITELIST */	":%s 347 %s %s :End of Channel Invite List",
/* 348 RPL_EXCEPTLIST */	":%s 348 %s %s %s!%s@%s",
/* 349 RPL_ENDOFEXCEPTLIST */	":%s 349 %s %s :End of Channel Exception List",
/* 350 */ (char *)NULL,
/* 351 RPL_VERSION */	":%s 351 %s %s.%s %s %s :%s",
/* 352 RPL_WHOREPLY */	":%s 352 %s %s %s %s %s %s %s :%d %s %s",
/* 353 RPL_NAMREPLY */	":%s 353 %s %s",
/* 354 RPL_WHOSPCRPL */ ":%s 354 %s",
/* 355 */ (char *)NULL,
/* 356 */ (char *)NULL,
/* 357 */ (char *)NULL,
/* 358 */ (char *)NULL,
/* 359 */ (char *)NULL,
/* 360 */ (char *)NULL,
/* 361 RPL_KILLDONE */	(char *)NULL,
/* 362 RPL_CLOSING */	":%s 362 %s %s :Closed. Status = %d",
/* 363 RPL_CLOSEEND */	":%s 363 %s %d: Connections Closed",
/* 364 RPL_LINKS */	":%s 364 %s %s %s :%d %s %s",
/* 365 RPL_ENDOFLINKS */	":%s 365 %s %s :End of LINKS list.",
/* 366 RPL_ENDOFNAMES */	":%s 366 %s %s :End of NAMES list.",
/* 367 RPL_BANLIST */	":%s 367 %s %s %s!%s@%s",
/* 368 RPL_ENDOFBANLIST */	":%s 368 %s %s :End of Channel Ban List",
/* 369 RPL_ENDOFWHOWAS */	":%s 369 %s %s :End of WHOWAS",
/* 370 */ (char *)NULL,
/* 371 RPL_INFO */	":%s 371 %s :%s",
/* 372 RPL_MOTD */	":%s 372 %s :- %s",
/* 373 RPL_INFOSTART */	":%s 373 %s :Server INFO",
/* 374 RPL_ENDOFINFO */	":%s 374 %s :End of INFO list.",
/* 375 RPL_MOTDSTART */	":%s 375 %s :- %s Message of the Day - ",
/* 376 RPL_ENDOFMOTD */	":%s 376 %s :End of MOTD command.",
/* 377 */ (char *)NULL,
/* 378 */ (char *)NULL,
/* 379 */ (char *)NULL,
/* 380 */ (char *)NULL,
/* 381 RPL_YOUREOPER */	":%s 381 %s :" TXT_YOUREOPER,
/* 382 RPL_REHASHING */	":%s 382 %s %s :Rehashing",
/* 383 RPL_YOURESERVICE */	":%s 383 %s :You are service %s",
/* 384 RPL_MYPORTIS */	":%s 384 %s %d :Port to local server is\r\n",
/* 385 RPL_NOTOPERANYMORE */	(char *)NULL,
/* 386 */ (char *)NULL,
/* 387 */ (char *)NULL,
/* 388 */ (char *)NULL,
/* 389 */ (char *)NULL,
/* 390 */ (char *)NULL,
/* 391 RPL_TIME */	":%s 391 %s %s :%s",
#if defined(USERS_RFC1459) && defined(USERS_SHOWS_UTMP)
/* 392 RPL_USERSSTART */	":%s 392 %s :UserID   Terminal  Host",
/* 393 RPL_USERS */	":%s 393 %s :%-8s %-9s %-8s",
/* 394 RPL_ENDOFUSERS */	":%s 394 %s :End of Users",
/* 395 RPL_NOUSERS */	":%s 395 %s :Nobody logged in.",
#else
/* 392 */ (char *)NULL,
/* 393 */ (char *)NULL,
/* 394 */ (char *)NULL,
/* 395 */ (char *)NULL,
#endif
/* 396 */ (char *)NULL,
/* 397 */ (char *)NULL,
/* 398 */ (char *)NULL,
/* 399 */ (char *)NULL,
/* 400 */ (char *)NULL,
/* 401 ERR_NOSUCHNICK */	":%s 401 %s %s :No such nick/channel",
/* 402 ERR_NOSUCHSERVER */	":%s 402 %s %s :No such server",
/* 403 ERR_NOSUCHCHANNEL */	":%s 403 %s %s :No such channel",
/* 404 ERR_CANNOTSENDTOCHAN */	":%s 404 %s %s :Cannot send to channel",
/* 405 ERR_TOOMANYCHANNELS */	":%s 405 %s %s :You have joined too many channels",
/* 406 ERR_WASNOSUCHNICK */	":%s 406 %s %s :There was no such nickname",
/* 407 ERR_TOOMANYTARGETS */	":%s 407 %s %s :%s recipients. %s",
/* 408 ERR_NOSUCHSERVICE */	":%s 408 %s %s :No such service",
/* 409 ERR_NOORIGIN */	":%s 409 %s :No origin specified",
/* 410 */ (char *)NULL,
/* 411 ERR_NORECIPIENT */	":%s 411 %s :No recipient given (%s)",
/* 412 ERR_NOTEXTTOSEND */	":%s 412 %s :No text to send",
/* 413 ERR_NOTOPLEVEL */	":%s 413 %s %s :No toplevel domain specified",
/* 414 ERR_WILDTOPLEVEL */	":%s 414 %s %s :Wildcard in toplevel Domain",
/* 415 ERR_BADMASK */	":%s 415 %s %s :Bad Server/host mask",
/* 416 ERR_TOOMANYMATCHES */	":%s 416 %s %s :output too large, truncated",
/* 417 */ (char *)NULL,
/* 418 */ (char *)NULL,
/* 419 */ (char *)NULL,
/* 420 */ (char *)NULL,
/* 421 ERR_UNKNOWNCOMMAND */	":%s 421 %s %s :Unknown command",
/* 422 ERR_NOMOTD */	":%s 422 %s :MOTD File is missing",
/* 423 ERR_NOADMININFO */	":%s 423 %s %s :No administrative info available",
/* 424 ERR_FILEERROR */	":%s 424 %s :File error doing %s on %s",
/* 425 */ (char *)NULL,
/* 426 */ (char *)NULL,
/* 427 */ (char *)NULL,
/* 428 */ (char *)NULL,
/* 429 */ (char *)NULL,
/* 430 */ (char *)NULL,
/* 431 ERR_NONICKNAMEGIVEN */	":%s 431 %s :No nickname given",
/* 432 ERR_ERRONEOUSNICKNAME */	":%s 432 %s %s :Erroneous Nickname",
/* 433 ERR_NICKNAMEINUSE */	":%s 433 %s %s :Nickname is already in use.",
/* 434 ERR_SERVICENAMEINUSE */	(char *)NULL,
/* 435 ERR_SERVICECONFUSED */	(char *)NULL,
/* 436 ERR_NICKCOLLISION */	":%s 436 %s %s :Nickname collision KILL from %s@%s",
/* 437 ERR_UNAVAILRESOURCE */	":%s 437 %s %s :Nick/channel is temporarily unavailable",
/* 438 */ (char *)NULL,
/* 439 */ (char *)NULL,
/* 440 */ (char *)NULL,
/* 441 ERR_USERNOTINCHANNEL */	":%s 441 %s %s %s :They aren't on that channel",
/* 442 ERR_NOTONCHANNEL */	":%s 442 %s %s :You're not on that channel",
/* 443 ERR_USERONCHANNEL */	":%s 443 %s %s %s :is already on channel",
/* 444 ERR_NOLOGIN */	":%s 444 %s %s :User not logged in",
#ifndef ENABLE_SUMMON
/* 445 ERR_SUMMONDISABLED */	":%s 445 %s :SUMMON has been disabled",
#else
/* 445 */ (char *)NULL,
#endif
#if defined(USERS_RFC1459) && !defined(USERS_SHOWS_UTMP)
/* 446 ERR_USERSDISABLED */	":%s 446 %s :USERS has been disabled",
#else
/* 446 */ (char *)NULL,
#endif
/* 447 */ (char *)NULL,
/* 448 */ (char *)NULL,
/* 449 */ (char *)NULL,
/* 450 */ (char *)NULL,
/* 451 ERR_NOTREGISTERED */	":%s 451 %s :You have not registered",
/* 452 */ (char *)NULL,
/* 453 */ (char *)NULL,
/* 454 */ (char *)NULL,
/* 455 */ (char *)NULL,
/* 456 */ (char *)NULL,
/* 457 */ (char *)NULL,
/* 458 */ (char *)NULL,
/* 459 */ (char *)NULL,
/* 460 */ (char *)NULL,
/* 461 ERR_NEEDMOREPARAMS */	":%s 461 %s %s :Not enough parameters",
/* 462 ERR_ALREADYREGISTRED */ ":%s 462 %s :Unauthorized command (already registered)",
/* 463 ERR_NOPERMFORHOST */	":%s 463 %s :Your host isn't among the privileged",
/* 464 ERR_PASSWDMISMATCH */	":%s 464 %s :Password Incorrect",
/* 465 ERR_YOUREBANNEDCREEP */	":%s 465 %s :You (%s@%s) are banned from this server%s%s",
/* 466 ERR_YOUWILLBEBANNED */	(char *)NULL,
/* 467 ERR_KEYSET */	":%s 467 %s %s :Channel key already set",
/* 468 */ (char *)NULL,
/* 469 */ (char *)NULL,
/* 470 */ (char *)NULL,
/* 471 ERR_CHANNELISFULL */	":%s 471 %s %s :Cannot join channel (+l)",
/* 472 ERR_UNKNOWNMODE   */	":%s 472 %s %c :is unknown mode char to me for %s",
/* 473 ERR_INVITEONLYCHAN */	":%s 473 %s %s :Cannot join channel (+i)",
/* 474 ERR_BANNEDFROMCHAN */	":%s 474 %s %s :Cannot join channel (+b)",
/* 475 ERR_BADCHANNELKEY */	":%s 475 %s %s :Cannot join channel (+k)",
/* 476 ERR_BADCHANMASK */	":%s 476 %s %s :Bad Channel Mask",
/* 477 ERR_JOINNEEDSASLAUTH */  ":%s 477 %s %s :Cannot join channel (+r) - you need to be authenticated with SASL", /*FIXME: good English? */
/* 478 ERR_BANLISTFULL */	":%s 478 %s %s %s!%s@%s :Channel list is full",
/* 479 */ (char *)NULL,
/* 480 */ (char *)NULL,
/* 481 ERR_NOPRIVILEGES */	":%s 481 %s :Permission Denied",
/* 482 ERR_CHANOPRIVSNEEDED */	":%s 482 %s %s :You're not channel operator",
/* 483 ERR_CANTKILLSERVER */	":%s 483 %s %s :You can't kill a server!",
/* 484 ERR_RESTRICTED */	":%s 484 %s :Your connection is restricted!",
/* 485 ERR_UNIQOPRIVSNEEDED */	":%s 485 %s :You're not the original channel operator",
/* 486 ERR_MSGNEEDSASLAUTH */ ":%s 486 %s %s :You need to be authenticated with SASL to message this user", /*FIXME: good English? */ // TODO: rename
/* 487 */ (char *)NULL,
/* 488 */ (char *)NULL,
/* 489 */ (char *)NULL,
/* 490 */ (char *)NULL,
/* 491 ERR_NOOPERHOST */	":%s 491 %s :No O-lines for your host",
/* 492 ERR_NOSERVICEHOST */	(char *)NULL,
/* 493 */ (char *)NULL,
/* 494 */ (char *)NULL,
/* 495 */ (char *)NULL,
/* 496 */ (char *)NULL,
/* 497 */ (char *)NULL,
/* 498 */ (char *)NULL,
#ifdef TXT_NOSTATSK
/* 499 */ 			":%s 499 %s :" TXT_NOSTATSK,
#else
/* 499 */ (char *)NULL,
#endif
/* 500 */ (char *)NULL,
/* 501 ERR_UMODEUNKNOWNFLAG */	":%s 501 %s :Unknown MODE flag",
/* 502 ERR_USERSDONTMATCH */	":%s 502 %s :Can't change mode for other users",
/* 503 */ (char *)NULL,
/* 504 */ (char *)NULL,
/* 505 */ (char *)NULL,
/* 506 */ (char *)NULL,
/* 507 */ (char *)NULL,
/* 508 */ (char *)NULL,
/* 509 */ (char *)NULL,
/* 510 */ (char *)NULL,
/* 511 */ (char *)NULL,
/* 512 */ (char *)NULL,
/* 513 */ (char *)NULL,
/* 514 */ (char *)NULL,
/* 515 */ (char *)NULL,
/* 516 */ (char *)NULL,
/* 517 */ (char *)NULL,
/* 518 */ (char *)NULL,
/* 519 */ (char *)NULL,
/* 520 */ (char *)NULL,
/* 521 */ (char *)NULL,
/* 522 */ (char *)NULL,
/* 523 */ (char *)NULL,
/* 524 */ (char *)NULL,
/* 525 */ (char *)NULL,
/* 526 */ (char *)NULL,
/* 527 */ (char *)NULL,
/* 528 */ (char *)NULL,
/* 529 */ (char *)NULL,
/* 530 */ (char *)NULL,
/* 531 */ (char *)NULL,
/* 532 */ (char *)NULL,
/* 533 */ (char *)NULL,
/* 534 */ (char *)NULL,
/* 535 */ (char *)NULL,
/* 536 */ (char *)NULL,
/* 537 */ (char *)NULL,
/* 538 */ (char *)NULL,
/* 539 */ (char *)NULL,
/* 540 */ (char *)NULL,
/* 541 */ (char *)NULL,
/* 542 */ (char *)NULL,
/* 543 */ (char *)NULL,
/* 544 */ (char *)NULL,
/* 545 */ (char *)NULL,
/* 546 */ (char *)NULL,
/* 547 */ (char *)NULL,
/* 548 */ (char *)NULL,
/* 549 */ (char *)NULL,
/* 550 */ (char *)NULL,
/* 551 */ (char *)NULL,
/* 552 */ (char *)NULL,
/* 553 */ (char *)NULL,
/* 554 */ (char *)NULL,
/* 555 */ (char *)NULL,
/* 556 */ (char *)NULL,
/* 557 */ (char *)NULL,
/* 558 */ (char *)NULL,
/* 559 */ (char *)NULL,
/* 560 */ (char *)NULL,
/* 561 */ (char *)NULL,
/* 562 */ (char *)NULL,
/* 563 */ (char *)NULL,
/* 564 */ (char *)NULL,
/* 565 */ (char *)NULL,
/* 566 */ (char *)NULL,
/* 567 */ (char *)NULL,
/* 568 */ (char *)NULL,
/* 569 */ (char *)NULL,
/* 570 */ (char *)NULL,
/* 571 */ (char *)NULL,
/* 572 */ (char *)NULL,
/* 573 */ (char *)NULL,
/* 574 */ (char *)NULL,
/* 575 */ (char *)NULL,
/* 576 */ (char *)NULL,
/* 577 */ (char *)NULL,
/* 578 */ (char *)NULL,
/* 579 */ (char *)NULL,
/* 580 */ (char *)NULL,
/* 581 */ (char *)NULL,
/* 582 */ (char *)NULL,
/* 583 */ (char *)NULL,
/* 584 */ (char *)NULL,
/* 585 */ (char *)NULL,
/* 586 */ (char *)NULL,
/* 587 */ (char *)NULL,
/* 588 */ (char *)NULL,
/* 589 */ (char *)NULL,
/* 590 */ (char *)NULL,
/* 591 */ (char *)NULL,
/* 592 */ (char *)NULL,
/* 593 */ (char *)NULL,
/* 594 */ (char *)NULL,
/* 595 */ (char *)NULL,
/* 596 */ (char *)NULL,
/* 597 */ (char *)NULL,
/* 598 */ (char *)NULL,
/* 599 */ (char *)NULL,
/* 600 */ (char *)NULL,
/* 601 */ (char *)NULL,
/* 602 */ (char *)NULL,
/* 603 */ (char *)NULL,
/* 604 */ (char *)NULL,
/* 605 */ (char *)NULL,
/* 606 */ (char *)NULL,
/* 607 */ (char *)NULL,
/* 608 */ (char *)NULL,
/* 609 */ (char *)NULL,
/* 610 */ (char *)NULL,
/* 611 */ (char *)NULL,
/* 612 */ (char *)NULL,
/* 613 */ (char *)NULL,
/* 614 */ (char *)NULL,
/* 615 */ (char *)NULL,
/* 616 */ (char *)NULL,
/* 617 */ (char *)NULL,
/* 618 */ (char *)NULL,
/* 619 */ (char *)NULL,
/* 620 */ (char *)NULL,
/* 621 */ (char *)NULL,
/* 622 */ (char *)NULL,
/* 623 */ (char *)NULL,
/* 624 */ (char *)NULL,
/* 625 */ (char *)NULL,
/* 626 */ (char *)NULL,
/* 627 */ (char *)NULL,
/* 628 */ (char *)NULL,
/* 629 */ (char *)NULL,
/* 630 */ (char *)NULL,
/* 631 */ (char *)NULL,
/* 632 */ (char *)NULL,
/* 633 */ (char *)NULL,
/* 634 */ (char *)NULL,
/* 635 */ (char *)NULL,
/* 636 */ (char *)NULL,
/* 637 */ (char *)NULL,
/* 638 */ (char *)NULL,
/* 639 */ (char *)NULL,
/* 640 */ (char *)NULL,
/* 641 */ (char *)NULL,
/* 642 */ (char *)NULL,
/* 643 */ (char *)NULL,
/* 644 */ (char *)NULL,
/* 645 */ (char *)NULL,
/* 646 */ (char *)NULL,
/* 647 */ (char *)NULL,
/* 648 */ (char *)NULL,
/* 649 */ (char *)NULL,
/* 650 */ (char *)NULL,
/* 651 */ (char *)NULL,
/* 652 */ (char *)NULL,
/* 653 */ (char *)NULL,
/* 654 */ (char *)NULL,
/* 655 */ (char *)NULL,
/* 656 */ (char *)NULL,
/* 657 */ (char *)NULL,
/* 658 */ (char *)NULL,
/* 659 */ (char *)NULL,
/* 660 */ (char *)NULL,
/* 661 */ (char *)NULL,
/* 662 */ (char *)NULL,
/* 663 */ (char *)NULL,
/* 664 */ (char *)NULL,
/* 665 */ (char *)NULL,
/* 666 */ (char *)NULL,
/* 667 */ (char *)NULL,
/* 668 */ (char *)NULL,
/* 669 */ (char *)NULL,
/* 670 */ (char *)NULL,
/* 671 */ (char *)NULL,
/* 672 */ (char *)NULL,
/* 673 */ (char *)NULL,
/* 674 */ (char *)NULL,
/* 675 */ (char *)NULL,
/* 676 */ (char *)NULL,
/* 677 */ (char *)NULL,
/* 678 */ (char *)NULL,
/* 679 */ (char *)NULL,
/* 680 */ (char *)NULL,
/* 681 */ (char *)NULL,
/* 682 */ (char *)NULL,
/* 683 */ (char *)NULL,
/* 684 */ (char *)NULL,
/* 685 */ (char *)NULL,
/* 686 */ (char *)NULL,
/* 687 */ (char *)NULL,
/* 688 */ (char *)NULL,
/* 689 */ (char *)NULL,
/* 690 */ (char *)NULL,
/* 691 */ (char *)NULL,
/* 692 */ (char *)NULL,
/* 693 */ (char *)NULL,
/* 694 */ (char *)NULL,
/* 695 */ (char *)NULL,
/* 696 */ (char *)NULL,
/* 697 */ (char *)NULL,
/* 698 */ (char *)NULL,
/* 699 */ (char *)NULL,
/* 700 */ (char *)NULL,
/* 701 */ (char *)NULL,
/* 702 */ (char *)NULL,
/* 703 */ (char *)NULL,
/* 704 */ (char *)NULL,
/* 705 */ (char *)NULL,
/* 706 */ (char *)NULL,
/* 707 */ (char *)NULL,
/* 708 RPL_ETRACEFULL */		":%s 709 %s %s %d %s %s %s %s %s %s :%s",
/* 709 */ (char *)NULL,
/* 710 */ (char *)NULL,
/* 711 */ (char *)NULL,
/* 712 */ (char *)NULL,
/* 713 */ (char *)NULL,
/* 714 */ (char *)NULL,
/* 715 */ (char *)NULL,
/* 716 */ (char *)NULL,
/* 717 */ (char *)NULL,
/* 718 */ (char *)NULL,
/* 719 */ (char *)NULL,
/* 720 */ (char *)NULL,
/* 721 */ (char *)NULL,
/* 722 */ (char *)NULL,
/* 723 */ (char *)NULL,
/* 724 */ (char *)NULL,
/* 725 */ (char *)NULL,
/* 726 */ (char *)NULL,
/* 727 */ (char *)NULL,
/* 728 */ (char *)NULL,
/* 729 */ (char *)NULL,
/* 730 */ (char *)NULL,
/* 731 */ (char *)NULL,
/* 732 */ (char *)NULL,
/* 733 */ (char *)NULL,
/* 734 */ (char *)NULL,
/* 735 */ (char *)NULL,
/* 736 */ (char *)NULL,
/* 737 */ (char *)NULL,
/* 738 */ (char *)NULL,
/* 739 */ (char *)NULL,
/* 740 */ (char *)NULL,
/* 741 */ (char *)NULL,
/* 742 */ (char *)NULL,
/* 743 */ (char *)NULL,
/* 744 */ (char *)NULL,
/* 745 */ (char *)NULL,
/* 746 */ (char *)NULL,
/* 747 */ (char *)NULL,
/* 748 */ (char *)NULL,
/* 749 */ (char *)NULL,
/* 750 */ (char *)NULL,
/* 751 */ (char *)NULL,
/* 752 */ (char *)NULL,
/* 753 */ (char *)NULL,
/* 754 */ (char *)NULL,
/* 755 */ (char *)NULL,
/* 756 */ (char *)NULL,
/* 757 */ (char *)NULL,
/* 758 */ (char *)NULL,
/* 759 RPL_ETRACEEND */ ":%s 759 %s %s %s.%s :End of ETRACE",
/* 760 */ (char *)NULL,
/* 761 */ (char *)NULL,
/* 762 */ (char *)NULL,
/* 763 */ (char *)NULL,
/* 764 */ (char *)NULL,
/* 765 */ (char *)NULL,
/* 766 */ (char *)NULL,
/* 767 */ (char *)NULL,
/* 768 */ (char *)NULL,
/* 769 */ (char *)NULL,
/* 770 */ (char *)NULL,
/* 771 */ (char *)NULL,
/* 772 */ (char *)NULL,
/* 773 */ (char *)NULL,
/* 774 */ (char *)NULL,
/* 775 */ (char *)NULL,
/* 776 */ (char *)NULL,
/* 777 */ (char *)NULL,
/* 778 */ (char *)NULL,
/* 779 */ (char *)NULL,
/* 780 */ (char *)NULL,
/* 781 */ (char *)NULL,
/* 782 */ (char *)NULL,
/* 783 */ (char *)NULL,
/* 784 */ (char *)NULL,
/* 785 */ (char *)NULL,
/* 786 */ (char *)NULL,
/* 787 */ (char *)NULL,
/* 788 */ (char *)NULL,
/* 789 */ (char *)NULL,
/* 790 */ (char *)NULL,
/* 791 */ (char *)NULL,
/* 792 */ (char *)NULL,
/* 793 */ (char *)NULL,
/* 794 */ (char *)NULL,
/* 795 */ (char *)NULL,
/* 796 */ (char *)NULL,
/* 797 */ (char *)NULL,
/* 798 */ (char *)NULL,
/* 799 */ (char *)NULL,
/* 800 */ (char *)NULL,
/* 801 */ (char *)NULL,
/* 802 */ (char *)NULL,
/* 803 */ (char *)NULL,
/* 804 */ (char *)NULL,
/* 805 */ (char *)NULL,
/* 806 */ (char *)NULL,
/* 807 */ (char *)NULL,
/* 808 */ (char *)NULL,
/* 809 */ (char *)NULL,
/* 810 */ (char *)NULL,
/* 811 */ (char *)NULL,
/* 812 */ (char *)NULL,
/* 813 */ (char *)NULL,
/* 814 */ (char *)NULL,
/* 815 */ (char *)NULL,
/* 816 */ (char *)NULL,
/* 817 */ (char *)NULL,
/* 818 */ (char *)NULL,
/* 819 */ (char *)NULL,
/* 820 */ (char *)NULL,
/* 821 */ (char *)NULL,
/* 822 */ (char *)NULL,
/* 823 */ (char *)NULL,
/* 824 */ (char *)NULL,
/* 825 */ (char *)NULL,
/* 826 */ (char *)NULL,
/* 827 */ (char *)NULL,
/* 828 */ (char *)NULL,
/* 829 */ (char *)NULL,
/* 830 */ (char *)NULL,
/* 831 */ (char *)NULL,
/* 832 */ (char *)NULL,
/* 833 */ (char *)NULL,
/* 834 */ (char *)NULL,
/* 835 */ (char *)NULL,
/* 836 */ (char *)NULL,
/* 837 */ (char *)NULL,
/* 838 */ (char *)NULL,
/* 839 */ (char *)NULL,
/* 840 */ (char *)NULL,
/* 841 */ (char *)NULL,
/* 842 */ (char *)NULL,
/* 843 */ (char *)NULL,
/* 844 */ (char *)NULL,
/* 845 */ (char *)NULL,
/* 846 */ (char *)NULL,
/* 847 */ (char *)NULL,
/* 848 */ (char *)NULL,
/* 849 */ (char *)NULL,
/* 850 */ (char *)NULL,
/* 851 */ (char *)NULL,
/* 852 */ (char *)NULL,
/* 853 */ (char *)NULL,
/* 854 */ (char *)NULL,
/* 855 */ (char *)NULL,
/* 856 */ (char *)NULL,
/* 857 */ (char *)NULL,
/* 858 */ (char *)NULL,
/* 859 */ (char *)NULL,
/* 860 */ (char *)NULL,
/* 861 */ (char *)NULL,
/* 862 */ (char *)NULL,
/* 863 */ (char *)NULL,
/* 864 */ (char *)NULL,
/* 865 */ (char *)NULL,
/* 866 */ (char *)NULL,
/* 867 */ (char *)NULL,
/* 868 */ (char *)NULL,
/* 869 */ (char *)NULL,
/* 870 */ (char *)NULL,
/* 871 */ (char *)NULL,
/* 872 */ (char *)NULL,
/* 873 */ (char *)NULL,
/* 874 */ (char *)NULL,
/* 875 */ (char *)NULL,
/* 876 */ (char *)NULL,
/* 877 */ (char *)NULL,
/* 878 */ (char *)NULL,
/* 879 */ (char *)NULL,
/* 880 */ (char *)NULL,
/* 881 */ (char *)NULL,
/* 882 */ (char *)NULL,
/* 883 */ (char *)NULL,
/* 884 */ (char *)NULL,
/* 885 */ (char *)NULL,
/* 886 */ (char *)NULL,
/* 887 */ (char *)NULL,
/* 888 */ (char *)NULL,
/* 889 */ (char *)NULL,
/* 890 */ (char *)NULL,
/* 891 */ (char *)NULL,
/* 892 */ (char *)NULL,
/* 893 */ (char *)NULL,
/* 894 */ (char *)NULL,
/* 895 */ (char *)NULL,
/* 896 */ (char *)NULL,
/* 897 */ (char *)NULL,
/* 898 */ (char *)NULL,
/* 899 */ (char *)NULL,
/* 900 RPL_LOGGEDIN */		":%s 900 %s :You are now logged in as %s.",
/* 901 */ (char *)NULL,
/* 902 */ (char *)NULL,
/* 903 RPL_SASLSUCCESS */   ":%s 903 %s :SASL authentication successful",
/* 904 ERR_SASLFAIL */		":%s 904 %s :SASL authentication failed",
/* 905 ERR_SASLTOOLONG */	":%s 905 %s :SASL message too long",
/* 906 ERR_SASLABORTED */	":%s 906 %s :SASL authentication aborted",
/* 907 ERR_SASLALREADY */	":%s 907 %s :You have already completed SASL authentication",
/* 908 RPL_SASLMECHS */     ":%s 908 %s %s :are available SASL mechanisms",
/* 909 */ (char *)NULL,
/* 910 */ (char *)NULL,
/* 911 */ (char *)NULL,
/* 912 */ (char *)NULL,
/* 913 */ (char *)NULL,
/* 914 */ (char *)NULL,
/* 915 */ (char *)NULL,
/* 916 */ (char *)NULL,
/* 917 */ (char *)NULL,
/* 918 */ (char *)NULL,
/* 919 */ (char *)NULL,
/* 920 */ (char *)NULL,
/* 921 */ (char *)NULL,
/* 922 */ (char *)NULL,
/* 923 */ (char *)NULL,
/* 924 */ (char *)NULL,
/* 925 */ (char *)NULL,
/* 926 */ (char *)NULL,
/* 927 */ (char *)NULL,
/* 928 */ (char *)NULL,
/* 929 */ (char *)NULL,
/* 930 */ (char *)NULL,
/* 931 */ (char *)NULL,
/* 932 */ (char *)NULL,
/* 933 */ (char *)NULL,
/* 934 */ (char *)NULL,
/* 935 */ (char *)NULL,
/* 936 */ (char *)NULL,
/* 937 */ (char *)NULL,
/* 938 */ (char *)NULL,
/* 939 */ (char *)NULL,
/* 940 */ (char *)NULL,
/* 941 */ (char *)NULL,
/* 942 */ (char *)NULL,
/* 943 */ (char *)NULL,
/* 944 */ (char *)NULL,
/* 945 */ (char *)NULL,
/* 946 */ (char *)NULL,
/* 947 */ (char *)NULL,
/* 948 */ (char *)NULL,
/* 949 */ (char *)NULL,
/* 950 */ (char *)NULL,
/* 951 */ (char *)NULL,
/* 952 */ (char *)NULL,
/* 953 */ (char *)NULL,
/* 954 */ (char *)NULL,
/* 955 */ (char *)NULL,
/* 956 */ (char *)NULL,
/* 957 */ (char *)NULL,
/* 958 */ (char *)NULL,
/* 959 */ (char *)NULL,
/* 960 */ (char *)NULL,
/* 961 */ (char *)NULL,
/* 962 */ (char *)NULL,
/* 963 */ (char *)NULL,
/* 964 */ (char *)NULL,
/* 965 */ (char *)NULL,
/* 966 */ (char *)NULL,
/* 967 */ (char *)NULL,
/* 968 */ (char *)NULL,
/* 969 */ (char *)NULL,
/* 970 */ (char *)NULL,
/* 971 */ (char *)NULL,
/* 972 */ (char *)NULL,
/* 973 */ (char *)NULL,
/* 974 */ (char *)NULL,
/* 975 */ (char *)NULL,
/* 976 */ (char *)NULL,
/* 977 */ (char *)NULL,
/* 978 */ (char *)NULL,
/* 979 */ (char *)NULL,
/* 980 */ (char *)NULL,
/* 981 */ (char *)NULL,
/* 982 */ (char *)NULL,
/* 983 */ (char *)NULL,
/* 984 */ (char *)NULL,
/* 985 */ (char *)NULL,
/* 986 */ (char *)NULL,
/* 987 */ (char *)NULL,
/* 988 */ (char *)NULL,
/* 989 */ (char *)NULL,
/* 990 */ (char *)NULL,
/* 991 */ (char *)NULL,
/* 992 */ (char *)NULL,
/* 993 */ (char *)NULL,
/* 994 */ (char *)NULL,
/* 995 */ (char *)NULL,
/* 996 */ (char *)NULL,
/* 997 */ (char *)NULL,
/* 998 */ (char *)NULL,
/* 999 */ (char *)NULL
};

