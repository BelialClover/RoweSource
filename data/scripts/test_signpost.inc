Text_ThisIsATestSignpostMsg:: @ 82C840A
	.string "This is a test message.\n"
	.string "This is a signpost.$"

EventScript_TestSignpostMsg:: @ 82C8436
	msgbox Text_ThisIsATestSignpostMsg, MSGBOX_SIGN
	end
	
Text_Flying_Follower::
	.string "Do you want to Fly\n"
	.string "with your Pokémon?$"
	
EventScript_Flying_Follower::
    lock
    faceplayer
    msgbox Text_Flying_Follower, MSGBOX_YESNO
    compare VAR_RESULT, YES
    goto_if_eq EventScript_Flying_Follower_ChooseDestination
    compare VAR_RESULT, NO
    goto_if_eq EventScript_Flying_Follower_Goodbye
    end
	
EventScript_Flying_Follower_ChooseDestination::
	setvar VAR_0x800A, LAST_TALKED_TO_FLYING_TAXI
    special FieldLoadFlyMap
    goto EventScript_Flying_Follower_Goodbye
    end

EventScript_Flying_Follower_Goodbye::
    setvar VAR_LAST_TALKED, 0
    releaseall
    return
	
EventScript_Normal_Follower::
    releaseall
    return
	end
	
gText_FollowerLovesYou::
  .string "{STR_VAR_1} is regarding you with\nadoration!$"

gText_FollowerLostInThought::
  .string "{STR_VAR_1} seems lost in thought.$"

gText_FollowerDefault::
  .string "ERROR 404: Script not found.$"

gText_FollowerUnhappyToBeWet::
  .string "{STR_VAR_1} looks unhappy to be wet.$"

gText_FollowerSplashesAround::
  .string "{STR_VAR_1} splashes around happily!$"

gText_WantsToFly::
  .string "{STR_VAR_1} looks up at the\nsky restlessly.\pWould you like to Fly?$"

gText_FollowerUnhappyFace::
  .string "{STR_VAR_1} is making an unhappy face...$"
  
gText_FollowerDislikesThisPlace::
  .string "It looks like {STR_VAR_1} \nreally dislikes this place$"
  
gText_FollowerLikesThisPlace::
  .string "It looks like {STR_VAR_1} \nis happy to be here$"

gText_FollowerHappyRain::
  .string "{STR_VAR_1} seems to be happy\nabout the rain!$"
  
gText_FollowerHappySnow::
  .string "{STR_VAR_1} is happily playing\nwith the snow!$"
  
gText_FollowerHoldingItem::
  .string "It looks like {STR_VAR_1} its holding\nsomething!$"
  
gText_FollowerPresent::
  .string "It looks like {STR_VAR_1} has a gift\nfor you!$"

gText_FollowerMetLocation::
  .string "{STR_VAR_1} looks around fondly.\nIt seems familiar with this place.$"

gText_FollowerSkeptical::
  .string "{STR_VAR_1} looks skeptical...\pWhat could it mean?$"

gText_FollowerAppraising::
  .string "{STR_VAR_1} carefully follows behind.$"
  
gText_FollowerPickup::
  .string "{STR_VAR_1} is carefully looking\naround for items.$"

gText_FollowerHappyWalk::
  .string "{STR_VAR_1} skips happily behind you!$"

gText_FollowerAboutToFall::
  .string "{STR_VAR_1} seems to be about\nto fall over!$"

gText_FollowerTryingToKeepUp::
  .string "{STR_VAR_1} is trying very hard\nto keep up with you...$"

gText_FollowerIsShivering::
  .string "{STR_VAR_1} is shivering.$"

gText_FollowerBurnPainful::
  .string "{STR_VAR_1}'s burn looks painful!$'"

.macro playfirstmoncry
callfunc ScrFunc_playfirstmoncry
.endm

.macro bufferlivemonspeciesname out:req
callfunc ScrFunc_bufferlivemonspeciesname
.byte \out
.endm

EventScript_Follower::
  lock
  faceplayer
  bufferlivemonspeciesname 0
  playfirstmoncry
  callfunc ScrFunc_getfolloweraction
  canFollowerFly
  compare VAR_RESULT 6
  goto_if_eq EventScript_FollowerEnd
  bufferlivemonspeciesname 0
  msgbox gText_WantsToFly, MSGBOX_YESNO
  switch VAR_RESULT
  case NO, EventScript_FollowerEnd
  case YES, EventScript_FollowerFly
  case MULTI_B_PRESSED, EventScript_FollowerEnd
EventScript_FollowerFly::
  callfunc ScrFunc_followerfly
EventScript_FollowerEnd::
  release
  end

EventScript_FollowerHappyWalk::
  msgbox gText_FollowerHappyWalk, MSGBOX_DEFAULT
  waitmoncry
  return
  
EventScript_FollowerPickup::
  msgbox gText_FollowerPickup, MSGBOX_DEFAULT
  waitmoncry
  return
  
EventScript_FollowerHoldingItem::
  msgbox gText_FollowerHoldingItem, MSGBOX_DEFAULT
  waitmoncry
  giveitem ITEM_POKE_BALL
  return
  
EventScript_FollowerPresent_1::
  msgbox gText_FollowerPresent, MSGBOX_DEFAULT
  waitmoncry
  giveitem ITEM_SNOWBALL
  return
  
EventScript_FollowerPresent_2::
  msgbox gText_FollowerPresent, MSGBOX_DEFAULT
  waitmoncry
  giveitem ITEM_CHARCOAL
  return

EventScript_FollowerAppraising::
  msgbox gText_FollowerAppraising, MSGBOX_DEFAULT
  waitmoncry
  return

EventScript_FollowerSkeptical::
  msgbox gText_FollowerSkeptical, MSGBOX_DEFAULT
  waitmoncry
  return

EventScript_FollowerMetLocation::
  applymovement 0xFE Common_Movement_QuestionMark
  waitmoncry
  waitmovement 0xFE
  msgbox gText_FollowerMetLocation, MSGBOX_DEFAULT
  return

EventScript_FollowerUnhappyFace::
  msgbox gText_FollowerUnhappyFace, MSGBOX_DEFAULT
  waitmoncry
  return
  
EventScript_FollowerDislikesThisPlace::
  msgbox gText_FollowerDislikesThisPlace, MSGBOX_DEFAULT
  waitmoncry
  return
  
EventScript_FollowerLikesThisPlace::
  msgbox gText_FollowerLikesThisPlace, MSGBOX_DEFAULT
  waitmoncry
  return
  
EventScript_FollowerHappySnow::
  msgbox gText_FollowerHappySnow, MSGBOX_DEFAULT
  waitmoncry
  return

EventScript_FollowerHappyRain::
  msgbox gText_FollowerHappyRain, MSGBOX_DEFAULT
  waitmoncry
  return

EventScript_FollowerUnhappyToBeWet::
  msgbox gText_FollowerUnhappyToBeWet, MSGBOX_DEFAULT
  waitmoncry
  return

EventScript_FollowerSplashesAbout::
  applymovement 0xFE FollowerSplashMovement
  waitmovement 0xFE
  msgbox gText_FollowerSplashesAround, MSGBOX_DEFAULT
  return

EventScript_FollowerLovesYou::
  applymovement 0xFE ContestHall_Movement_Heart
  waitmovement 0xFE
  waitmoncry
  msgbox gText_FollowerLovesYou, MSGBOX_DEFAULT
  return

EventScript_FollowerAboutToFall::
  msgbox gText_FollowerAboutToFall, MSGBOX_DEFAULT
  waitmoncry
  return

EventScript_FollowerTryingToKeepUp::
  msgbox gText_FollowerTryingToKeepUp, MSGBOX_DEFAULT
  waitmoncry
  return

EventScript_FollowerIsShivering::
  msgbox gText_FollowerIsShivering, MSGBOX_DEFAULT
  waitmoncry
  return

EventScript_FollowerBurnPainful::
  msgbox gText_FollowerBurnPainful, MSGBOX_DEFAULT
  waitmoncry
  return

FollowerSplashMovement:: @ defined in movement.inc
  jump_in_place_down
  delay_4
  jump_in_place_down
  face_player
  step_end

