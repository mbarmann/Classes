<%@ Page Title="" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="DeleteProducts.aspx.cs" Inherits="MatthewBarmann.Pages.DeleteProducts" %>
<asp:Content ID="Content1" ContentPlaceHolderID="MainContent" runat="server">   
    <h2>Manage the Products Table</h2>
    <div style="padding:25px;"> 
      <aside style="float:left; width: 300px;">
         <h2>Choose a Product to Delete</h2><br /> 
         <asp:DropDownList ID="ddlProductList" runat="server" AutoPostBack="true" 
                >
         </asp:DropDownList> 
         <br /><asp:Label ID="Message" runat="server" Text="" /><br /> 
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
