/**************************************************************************/
/*                                                                        */
/*                              WWIV Version 5.x                          */
/*                Copyright (C)2016, WWIV Software Services               */
/*                                                                        */
/*    Licensed  under the  Apache License, Version  2.0 (the "License");  */
/*    you may not use this  file  except in compliance with the License.  */
/*    You may obtain a copy of the License at                             */
/*                                                                        */
/*                http://www.apache.org/licenses/LICENSE-2.0              */
/*                                                                        */
/*    Unless  required  by  applicable  law  or agreed to  in  writing,   */
/*    software  distributed  under  the  License  is  distributed on an   */
/*    "AS IS"  BASIS, WITHOUT  WARRANTIES  OR  CONDITIONS OF ANY  KIND,   */
/*    either  express  or implied.  See  the  License for  the specific   */
/*    language governing permissions and limitations under the License.   */
/*                                                                        */
/**************************************************************************/
#include "gtest/gtest.h"

#include <cstring>
#include <type_traits>

#include "core/stl.h"
#include "sdk/fido/nodelist.h"

using std::cout;
using std::endl;
using std::is_standard_layout;
using std::string;

using namespace wwiv::sdk;
using namespace wwiv::stl;
using namespace wwiv::sdk::fido;

TEST(NodelistTest, Basic) {
  NodelistEntry e = NodelistEntry::ParseDataLine(",1,system_name,location,sysop_name,phone_number,baud_rate,CM,INA:host:port");
  EXPECT_EQ(e.name_, "system_name");
}

TEST(NodelistTest, Zone) {
  NodelistEntry e = NodelistEntry::ParseDataLine("zone,1,system_name,location,sysop_name,phone_number,baud_rate,CM,INA:host:port");
  EXPECT_EQ(e.name_, "system_name");
}
