<%@ Page Title="" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="Homework2.aspx.cs" Inherits="MatthewBarmann.Pages.Homework2" %>
<asp:Content ID="Content1" ContentPlaceHolderID="MainContent" runat="server">
	<div>
		<asp:Label ID="pageLabel" runat="server" Text="Visitor Signup Page"/>
	</div>
	<div>
        <asp:Image ID="Image1" runat="server" ImageUrl="~/Images/pen_and_paper.png" Width="200" Height="200" />
    </div>
		<div id="myForm" runat="server" class="table"> 
			<table>
				<tr>
					<td>
						<asp:Label ID="fNameLabel" runat="server" Text="First Name"/>
					</td>		
					<td>
						<asp:TextBox ID="fName"  runat="server" /> 
					</td>
					<td>
						<asp:RequiredFieldValidator ID="RequiredFieldValidator1" runat="server" ControlToValidate="fName" ErrorMessage="Please enter a first name." Display="Dynamic">
						</asp:RequiredFieldValidator>
					</td>
				</tr>

				<tr>
					<td>
						<asp:Label ID="lNameLabel" runat="server" Text="Last Name"/>
					</td>
					<td>
						<asp:TextBox ID="lName" runat="server" /> 
					</td>
					<td>
						<asp:RequiredFieldValidator ID="RequiredFieldValidator2" runat="server" ControlToValidate="lName" ErrorMessage="Please enter a last name." Display="Dynamic">
						</asp:RequiredFieldValidator>
					</td>
				</tr>

				<tr>
					<td>
						<asp:Label ID="addressLabel" runat="server" Text="Address"/>
					</td>
					<td>
						<asp:TextBox ID="address" runat="server" /> 
					</td>
					<td>
						<asp:RequiredFieldValidator ID="RequiredFieldValidator3" runat="server" ControlToValidate="address" ErrorMessage="Please enter an address." Display="Dynamic">
						</asp:RequiredFieldValidator>
					</td>
				</tr>

				<tr>
					<td>
						<asp:Label ID="cityLabel" runat="server" Text="City"/>
					</td>
					<td>
						<asp:TextBox ID="city" runat="server" /> 
					</td>
					<td>
						<asp:RequiredFieldValidator ID="RequiredFieldValidator4" runat="server" ControlToValidate="city" ErrorMessage="Please enter a city." Display="Dynamic">
						</asp:RequiredFieldValidator>
					</td>
				</tr>

				<tr>
					<td>
						<asp:Label ID="stateLabel" runat="server" Text="State"/>
					</td>
					<td>
						<asp:dropdownlist runat="server" id="state">
				<asp:ListItem Value="">State</asp:ListItem>
				<asp:ListItem Value="AL">AL</asp:ListItem>
				<asp:ListItem Value="AK">AK</asp:ListItem>
				<asp:ListItem Value="AZ">AZ</asp:ListItem>
				<asp:ListItem Value="AR">AR</asp:ListItem>
				<asp:ListItem Value="CA">CA</asp:ListItem>
				<asp:ListItem Value="CO">CO</asp:ListItem>
				<asp:ListItem Value="CT">CT</asp:ListItem>
				<asp:ListItem Value="DC">DC</asp:ListItem>
				<asp:ListItem Value="DE">DE</asp:ListItem>
				<asp:ListItem Value="FL">FL</asp:ListItem>
				<asp:ListItem Value="GA">GA</asp:ListItem>
				<asp:ListItem Value="HI">HI</asp:ListItem>
				<asp:ListItem Value="ID">ID</asp:ListItem>
				<asp:ListItem Value="IL">IL</asp:ListItem>
				<asp:ListItem Value="IN">IN</asp:ListItem>
				<asp:ListItem Value="IA">IA</asp:ListItem>
				<asp:ListItem Value="KS">KS</asp:ListItem>
				<asp:ListItem Value="KY">KY</asp:ListItem>
				<asp:ListItem Value="LA">LA</asp:ListItem>
				<asp:ListItem Value="ME">ME</asp:ListItem>
				<asp:ListItem Value="MD">MD</asp:ListItem>
				<asp:ListItem Value="MA">MA</asp:ListItem>
				<asp:ListItem Value="MI">MI</asp:ListItem>
				<asp:ListItem Value="MN">MN</asp:ListItem>
				<asp:ListItem Value="MS">MS</asp:ListItem>
				<asp:ListItem Value="MO">MO</asp:ListItem>
				<asp:ListItem Value="MT">MT</asp:ListItem>
				<asp:ListItem Value="NE">NE</asp:ListItem>
				<asp:ListItem Value="NV">NV</asp:ListItem>
				<asp:ListItem Value="NH">NH</asp:ListItem>
				<asp:ListItem Value="NJ">NJ</asp:ListItem>
				<asp:ListItem Value="NM">NM</asp:ListItem>
				<asp:ListItem Value="NY">NY</asp:ListItem>
				<asp:ListItem Value="NC">NC</asp:ListItem>
				<asp:ListItem Value="ND">ND</asp:ListItem>
				<asp:ListItem Value="OH">OH</asp:ListItem>
				<asp:ListItem Value="OK">OK</asp:ListItem>
				<asp:ListItem Value="OR">OR</asp:ListItem>
				<asp:ListItem Value="PA">PA</asp:ListItem>
				<asp:ListItem Value="RI">RI</asp:ListItem>
				<asp:ListItem Value="SC">SC</asp:ListItem>
				<asp:ListItem Value="SD">SD</asp:ListItem>
				<asp:ListItem Value="TN">TN</asp:ListItem>
				<asp:ListItem Value="TX">TX</asp:ListItem>
				<asp:ListItem Value="UT">UT</asp:ListItem>
				<asp:ListItem Value="VT">VT</asp:ListItem>
				<asp:ListItem Value="VA">VA</asp:ListItem>
				<asp:ListItem Value="WA">WA</asp:ListItem>
				<asp:ListItem Value="WV">WV</asp:ListItem>
				<asp:ListItem Value="WI">WI</asp:ListItem>
				<asp:ListItem Value="WY">WY</asp:ListItem>
			</asp:dropdownlist>
					</td>
					<td>
						<asp:RequiredFieldValidator ID="RequiredFieldValidator5" runat="server" ControlToValidate="state" 
							ErrorMessage="Please select a state." Display="Dynamic">
						</asp:RequiredFieldValidator>
					</td>
				</tr>

				<tr>
					<td>
						<asp:Label ID="zipLabel" runat="server" Text="Zip Code"/>
					</td>
					<td>
						<asp:TextBox ID="zip" runat="server" /> 
					</td>
					<td>
						<asp:RequiredFieldValidator ID="RequiredFieldValidator6" runat="server" ControlToValidate="zip" 
							ErrorMessage="Please enter a zip." Display="Dynamic">
						</asp:RequiredFieldValidator>
						<asp:RegularExpressionValidator ID="RegularExpressionValidator1" ControlToValidate="zip" runat="server" 
							ErrorMessage="Enter valid zip code" ValidationExpression="\d+" MinimumValue="5" MaximumValue="5">
						</asp:RegularExpressionValidator>
					</td>
				</tr>

				<tr>
					<td>
						<asp:Label ID="numberLabel" runat="server" Text="Phone Number"/>
					</td>
					<td>
						<asp:TextBox ID="number" runat="server" /> 
					</td>
					<td>
						<asp:RequiredFieldValidator ID="RequiredFieldValidator7" runat="server" ControlToValidate="number" 
							ErrorMessage="Please enter a phone number." Display="Dynamic">
						</asp:RequiredFieldValidator>
					</td>
				</tr>

				<tr>
					<td>
						<asp:Label ID="emailLabel" runat="server" Text="Email Address"/>
					</td>
					<td>
						<asp:TextBox ID="email" runat="server" /> 
					</td>
					<td>
						<asp:RequiredFieldValidator ID="RequiredFieldValidator8" runat="server" ControlToValidate="email" 
							ErrorMessage="Please enter an email." Display="Dynamic">
						</asp:RequiredFieldValidator>
						<asp:RegularExpressionValidator id="vldEmail" 
							runat="server" ErrorMessage="Invalid email." 
							ValidationExpression=".+@.+" ControlToValidate="email" Width="232px">
						</asp:RegularExpressionValidator>
					</td>
				</tr>

				<tr>
					<td>
						<asp:Label ID="usernameLabel" runat="server" Text="Username"/>
					</td>
					<td>
						<asp:TextBox ID="username" runat="server" /> 
					</td>
					<td>
						<asp:RequiredFieldValidator ID="RequiredFieldValidator9" runat="server" ControlToValidate="username" 
							ErrorMessage="Please enter a username." Display="Dynamic">
						</asp:RequiredFieldValidator>
						<asp:RegularExpressionValidator ID="RegularExpressionValidator2" runat="server" ControlToValidate = "username" 
							ValidationExpression = "^[\s\S]{6,}$" ErrorMessage="Minimum 6 characters required." Display = "Dynamic">
						</asp:RegularExpressionValidator>
					</td>
				</tr>
				<tr>
					<asp:Label ID="passwordHelper" runat="server" Text="Password must be 8 letters or more and a mix of upper, lower and special characters and numbers." />
				</tr>
				<tr>
					<td>
						<asp:Label ID="passwordLabel" runat="server" Text="Password"/>
					</td>
					<td>
						<asp:TextBox ID="password" TextMode="Password" runat="server" /> 
					</td>
					<td>
						<asp:RequiredFieldValidator ID="RequiredFieldValidator10" runat="server" ControlToValidate="password" 
							ErrorMessage="Please enter a password." Display="Dynamic">
						</asp:RequiredFieldValidator>
						<asp:RegularExpressionValidator ID="RegularExpressionValidator13" runat="server" ControlToValidate="password"
							ValidateExpression="^(?=.*[a-z])(?=.*[A-Z])(?=.*\d)(?=.*[@$!%*?&])[A-Za-z\d@$!%*?&]{8,}$" ErrorMessage="Please enter a valid password" Display="Dynamic" />
					</td>
				</tr>

				<tr>
					<td>
						<asp:Label ID="dateLabel" runat="server" Text="Date"/>
					</td>
					<td>
						<asp:TextBox ID="date" runat="server" />
					</td>
					<td>
						<asp:RequiredFieldValidator ID="RequiredFieldValidator11" runat="server" ControlToValidate="date" 
							ErrorMessage="Please enter a date." Display="Dynamic">
						</asp:RequiredFieldValidator>
					</td>
				</tr>
		
				<tr>
					<td>
						<asp:Label ID="parkAreasLabel" runat="server" Text="Park area visited"/>
					</td>
					<td>
						<asp:CheckBoxList runat="server" ID ="parkAreas">
							<asp:ListItem Value="aquaCenter">Aquatic Center</asp:ListItem>
							<asp:ListItem Value="ausOutback">Australian Outback</asp:ListItem>
							<asp:ListItem Value="rainForest">Rainforest</asp:ListItem>
							<asp:ListItem Value="safari">African Safari</asp:ListItem>
							<asp:ListItem Value="reptile">Reptile Center</asp:ListItem>
						</asp:CheckBoxList>
					</td>
				</tr>

				<tr>
					<td>
						<asp:Label ID="travelLabel" runat="server" Text="Travel method"/>
					</td>
					<td>
						<asp:dropdownlist runat="server" id="travel">
				<asp:ListItem Value="bus">Bus</asp:ListItem>
				<asp:ListItem Value="bike">Bike</asp:ListItem>
				<asp:ListItem Value="car">Car</asp:ListItem>
				<asp:ListItem Value="taxi">Taxi</asp:ListItem>
				<asp:ListItem Value="uber">Uber</asp:ListItem>
				<asp:ListItem Value="walk">Walk</asp:ListItem>
			</asp:dropdownlist>
					</td>
					<td>
						<asp:RequiredFieldValidator ID="RequiredFieldValidator13" runat="server" ControlToValidate="fName" 
							ErrorMessage="Please select a travel method." Display="Dynamic">
						</asp:RequiredFieldValidator>
					</td>
				</tr>

				<tr>
					<td>
						<asp:Label ID="contactPrefLabel" runat="server" Text="Contact preference"/>
					</td>
					<td>
						<asp:RadioButtonList ID="contactPref" runat="server"> 
							<asp:ListItem Value="email" Checked="on" Selected="True">email</asp:ListItem>
							<asp:ListItem Value="phone">phone</asp:ListItem>
							<asp:ListItem Value="mail">mail</asp:ListItem>
						</asp:RadioButtonList>
					</td>
					<td>
						<asp:RequiredFieldValidator ID="RequiredFieldValidator14" runat="server" ControlToValidate="fName" 
							ErrorMessage="Please select a contact preference." Display="Dynamic">
						</asp:RequiredFieldValidator>
					</td>
				</tr>

				<tr>
					<td>
						<asp:Button id = "cmdSubmit" runat="server" Width="120px" Text="Submit" OnClick="cmdSubmit_Click"></asp:Button>
					</td>
					<td>
						<asp:Label id = "message" runat="server" Width="616px" Height="72px"></asp:Label><br /><br />
						<asp:ValidationSummary
							id="ValidationSummary1"
							ShowMessageBox="true"
							ShowSummary="false"
							Runat="server" />
					</td>
				</tr>
			</table>
		</div>
		<div>
			<asp:Label ID="myResults" runat="server" Text=""></asp:Label> 
		</div>
</asp:Content>