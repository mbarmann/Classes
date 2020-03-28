<%@ Page Title="" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="index.aspx.cs" Inherits="MatthewBarmann.Pages.index" %>
<asp:Content ID="Content1" ContentPlaceHolderID="MainContent" runat="server">
    <h2>Display Categories</h2><br /> 
    <asp:Table ID="CategoryTable" runat="server" 
          BorderColor="#CCCCCC" BorderStyle="Double" BorderWidth="1px" 
          GridLines="Both" CellPadding="10" >
    <asp:TableHeaderRow>
          <asp:TableHeaderCell>Category ID</asp:TableHeaderCell> 
          <asp:TableHeaderCell>Category Name</asp:TableHeaderCell>
          <asp:TableHeaderCell>Description</asp:TableHeaderCell>
          <asp:TableHeaderCell>Picture</asp:TableHeaderCell>
          <asp:TableHeaderCell>Thumbnail</asp:TableHeaderCell>
    </asp:TableHeaderRow>
    </asp:Table>
    <asp:Label ID="Message" runat="server" Text=""></asp:Label>  
    <asp:HyperLink id="hyperlink1" 
                  NavigateUrl="DeleteProducts.aspx"
                  Text=""
                  runat="server"/> 
    <asp:HyperLink id="hyperlink2" 
                  NavigateUrl="DisplayCategories.aspx"
                  Text=""
                  runat="server"/> 
    <asp:HyperLink id="hyperlink3" 
                  NavigateUrl="DisplayProducts.aspx"
                  Text=""
                  runat="server"/> 
    <asp:HyperLink id="hyperlink4" 
                  NavigateUrl="InsertProducts.aspx"
                  Text=""
                  runat="server"/> 
    <asp:HyperLink id="hyperlink5" 
                  NavigateUrl="UpdateProducts.aspx"
                  Text=""
                  runat="server"/> 
</asp:Content>
