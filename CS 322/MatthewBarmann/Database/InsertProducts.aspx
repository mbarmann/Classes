<%@ Page Title="" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="InsertProducts.aspx.cs" Inherits="MatthewBarmann.Pages.InsertProducts" %>
<asp:Content ID="Content1" ContentPlaceHolderID="MainContent" runat="server">  
    <h2>Insert a Product</h2>
    <div style="padding:25px;"> 

    <aside style="float:left; width: 300px;">
        Insert a New Product<br /><br />
        <asp:TextBox ID="TextBox1" runat="server">Product ID</asp:TextBox><br /><br />
        <asp:TextBox ID="TextBox2" runat="server">Product Name</asp:TextBox><br /><br />
        <asp:TextBox ID="TextBox3" runat="server">Category ID</asp:TextBox><br /><br />
        <asp:TextBox ID="TextBox4" runat="server">Category Name</asp:TextBox><br /><br />
        <asp:TextBox ID="TextBox5" runat="server">Description</asp:TextBox><br /><br />
        <asp:TextBox ID="TextBox6" runat="server">Inventory</asp:TextBox><br /><br />
        <asp:TextBox ID="TextBox7" runat="server">Cost</asp:TextBox><br /><br />
        <asp:TextBox ID="TextBox8" runat="server">Price</asp:TextBox><br /><br />
        <asp:TextBox ID="TextBox9" runat="server">Weight</asp:TextBox><br /><br />
        <asp:TextBox ID="TextBox10" runat="server">Product Image</asp:TextBox><br /><br />
        <asp:TextBox ID="TextBox11" runat="server">Product Thumbnail</asp:TextBox><br /><br />  
 
        <asp:Button ID="btnInsert" runat="server" Text="Insert a New Product" 
             OnClick="btnInsert_Click" /><br /><br /><br />  
        <asp:Label ID="Message" runat="server" Text="" /><br /> 
    </aside>

    <section style="float:right;width: 300px;"> 
          All Products<br /><br />
          <asp:Table ID="ProductTable" runat="server" 
             BorderColor="#CCCCCC" BorderStyle="Double" BorderWidth="1px" 
             GridLines="Both" CellPadding="10"> 
             <asp:TableHeaderRow> 
                <asp:TableHeaderCell>Product ID</asp:TableHeaderCell> 
                <asp:TableHeaderCell>Product Name</asp:TableHeaderCell> 
                <asp:TableHeaderCell>Category ID</asp:TableHeaderCell> 
                <asp:TableHeaderCell>Category Name</asp:TableHeaderCell> 
                <asp:TableHeaderCell>Description</asp:TableHeaderCell> 
                <asp:TableHeaderCell>Inventory</asp:TableHeaderCell> 
                <asp:TableHeaderCell>Cost</asp:TableHeaderCell> 
                <asp:TableHeaderCell>Price</asp:TableHeaderCell> 
                <asp:TableHeaderCell>Weight</asp:TableHeaderCell> 
                <asp:TableHeaderCell>Product Image</asp:TableHeaderCell> 
                <asp:TableHeaderCell>Product Thumbnail</asp:TableHeaderCell> 
             </asp:TableHeaderRow> 
          </asp:Table>  
    </section>
    </div>
</asp:Content>
