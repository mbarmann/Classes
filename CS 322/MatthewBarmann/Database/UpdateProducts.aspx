<%@ Page Title="" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="UpdateProducts.aspx.cs" Inherits="MatthewBarmann.Pages.UpdateProducts" %>
<asp:Content ID="Content1" ContentPlaceHolderID="MainContent" runat="server"> 
    <h2>Update a Product</h2>
    <asp:Label ID="Instructions" runat="server" Text="Select a product to display below in order to update"></asp:Label><br />
    <asp:DropDownList ID="ddlProductId" runat="server"></asp:DropDownList><br /><br />
    <asp:Button ID="btnUpdate" runat="server" Text="Choose a Product" OnClick="btnUpdate_Click" /> <br /><br />
    <asp:Label ID="UpdateResponse" runat="server" Text=""></asp:Label><br />

    <asp:TextBox ID="product_ID" runat="server">Product ID</asp:TextBox><br /><br />
    <asp:TextBox ID="name" runat="server">Product Name</asp:TextBox><br /><br />
    <asp:TextBox ID="category_ID" runat="server">Category ID</asp:TextBox><br /><br />
    <asp:TextBox ID="category_name" runat="server">Category Name</asp:TextBox><br /><br />
    <asp:TextBox ID="description" runat="server">Description</asp:TextBox><br /><br />
    <asp:TextBox ID="inventory_num" runat="server">Inventory</asp:TextBox><br /><br />
    <asp:TextBox ID="cost" runat="server">Cost</asp:TextBox><br /><br />
    <asp:TextBox ID="price" runat="server">Price</asp:TextBox><br /><br />
    <asp:TextBox ID="weight" runat="server">Weight</asp:TextBox><br /><br />
    <asp:TextBox ID="image" runat="server">Product Image</asp:TextBox><br /><br />
    <asp:TextBox ID="thumbnail" runat="server">Product Thumbnail</asp:TextBox>
    <br />
    <br />
    <asp:Button ID="btnSubmit" runat="server" Text="Update Product" OnClick="btnSubmit_Click" />
    <br /><br /> 
</asp:Content>
