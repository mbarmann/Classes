<%@ Page Title="" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="Homework4.aspx.cs" Inherits="MatthewBarmann.Pages.Homework4" %>
<asp:Content ID="Content1" ContentPlaceHolderID="MainContent" runat="server">
    <div>
        <asp:Label ID="video_content" runat="server" Text="Video Content" Font-Bold="true" Font-Size="Large" Height="50px" />
    </div>
    <div>
        <asp:Image ID="Image1" runat="server" ImageUrl="~/Images/photog.jfif" Width="300" Height="200" />
    </div>
    <div>
        <asp:Label ID="Label1" runat="server" Text="Check out some content from our youtube channel" Font-Bold="true" Font-Size="Large" Height="50px" />
    </div>
    <div>
        <iframe width="560" height="315" src="https://www.youtube.com/embed/jNQXAC9IVRw" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
    </div>
    <div>
         <asp:Label ID="Label2" runat="server" Text="We even have livestreams" Font-Bold="true" Font-Size="Large" Height="50px" />
    </div>
    <div>
        <iframe width="1200" height="675" src="https://www.youtube.com/embed/IisHeJRXU3M" frameborder="0" allow="accelerometer; autoplay; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>
    </div>
    <div>
        <asp:Label ID="Label3" runat="server" Text="If you want more check out these streams" Font-Bold="true" Font-Size="Large" Height="50px" />
    </div>
    <div>
        <ul>
          <li><asp:HyperLink id="kingp" NavigateUrl="https://www.kansascityzoo.org/ouranimals/list-of-animals/king-penguin/" 
            Text="If you want more check out these streams" Target="_blank"
            runat="server"/> </li>
          <li><asp:HyperLink id="gentoo" NavigateUrl="https://www.kansascityzoo.org/ouranimals/list-of-animals/gentoo-penguin/" 
            Text="If you want more check out these streams" Target="_blank"
            runat="server"/> </li>
          <li><asp:HyperLink id="polar_bear" NavigateUrl="https://www.kansascityzoo.org/ouranimals/list-of-animals/polar-bear/" 
            Text="If you want more check out these streams" Target="_blank"
            runat="server"/> </li>
          <li><asp:HyperLink id="giraffe" NavigateUrl="https://www.kansascityzoo.org/ouranimals/list-of-animals/masai-giraffe/" 
            Text="If you want more check out these streams" Target="_blank"
            runat="server"/> </li>
        </ul>  
    </div>
    <div>
        <asp:Label ID="Label4" runat="server" Text="Livestream Schedule" Font-Bold="true" Font-Size="Large" Height="50px" />
    </div>
    <div>
        <asp:Table ID="table" runat="server">
            <asp:TableHeaderRow>
                <asp:TableHeaderCell>
                    <asp:Label ID="Label5" runat="server" Text="Livestream" Font-Bold="true" Font-Size="Large" Height="50px" />
                </asp:TableHeaderCell>
                <asp:TableHeaderCell>
                    <asp:Label ID="Label6" runat="server" Text="Times" Font-Bold="true" Font-Size="Large" Height="50px" />
                </asp:TableHeaderCell>
            </asp:TableHeaderRow>
            <asp:TableRow>
                <asp:TableCell>
                    King Penguin
                </asp:TableCell>
                <asp:TableCell>
                    24/7
                </asp:TableCell>
            </asp:TableRow>
            <asp:TableRow>
                <asp:TableCell>
                    Gentoo Penguin
                </asp:TableCell>
                <asp:TableCell>
                    Mon-Thu, 5am-4pm
                </asp:TableCell>
            </asp:TableRow>
            <asp:TableRow>
                <asp:TableCell>
                    Polar Bear
                </asp:TableCell>
                <asp:TableCell>
                    Sat & Sun, 24 hrs
                </asp:TableCell>
            </asp:TableRow>
            <asp:TableRow>
                <asp:TableCell>
                    Giraffe
                </asp:TableCell>
                <asp:TableCell>
                    Mon-Fri, 7am-9pm
                </asp:TableCell>
            </asp:TableRow>
        </asp:Table>
    </div>
    <div>
        <asp:Label ID="Label7" runat="server" Text="Sign up for our Newsletter" Font-Bold="true" Font-Size="Large" Height="50px" />
    </div>
    <div>
        <asp:UpdatePanel runat="server" id="UpdatePanel1" updatemode="Conditional">           
            <ContentTemplate>
                <asp:Label runat="server" id="emailLabel" Text="Email:" />
                <asp:TextBox ID="email" runat="server" /> 
                <asp:RequiredFieldValidator ID="RequiredFieldValidator1" runat="server" 
                    ControlToValidate="email" ErrorMessage="Please enter an email." Display="Dynamic">
						</asp:RequiredFieldValidator>
                <asp:ImageButton id="imagebutton1" runat="server"
                   AlternateText="Sign Up"
                   ImageUrl="~/Images/thumbsup.png"
                    width="50px"
                    height="50px"
                   OnClick="submitOn_Click"/>
                <div>
                    <asp:label id="submitResponse" runat="server"/>
                </div>
            </ContentTemplate>
        </asp:UpdatePanel>
    </div>
</asp:Content>