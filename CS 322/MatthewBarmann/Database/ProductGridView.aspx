<%@ Page Title="" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="ProductGridView.aspx.cs" Inherits="MatthewBarmann.Pages.ProductGridView" %>
<asp:Content ID="Content1" ContentPlaceHolderID="MainContent" runat="server"> 
    <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="<%$ ConnectionStrings:Barmann %>" 
        DeleteCommand="DELETE FROM [products] WHERE [product_ID] = @product_ID" 
        InsertCommand="INSERT INTO [products] ([product_ID], [name], [category_ID], [category_name], [description], [inventory_num], [cost], [price], [weight], [image], [thumbnail]) VALUES (@product_ID, @name, @category_ID, @category_name, @description, @inventory_num, @cost, @price, @weight, @image, @thumbnail)" 
        OnSelecting="SqlDataSource1_Selecting" 
        SelectCommand="SELECT [product_ID], [name], [category_ID], [category_name], [description], [inventory_num], [cost], [price], [weight], [image], [thumbnail] FROM [products]" UpdateCommand="UPDATE [products] SET [name] = @name, [category_ID] = @category_ID, [category_name] = @category_name, [description] = @description, [inventory_num] = @inventory_num, [cost] = @cost, [price] = @price, [weight] = @weight, [image] = @image, [thumbnail] = @thumbnail WHERE [product_ID] = @product_ID">
        <DeleteParameters>
            <asp:Parameter Name="product_ID" Type="Int32" />
        </DeleteParameters>
        <InsertParameters>
            <asp:Parameter Name="product_ID" Type="Int32" />
            <asp:Parameter Name="name" Type="String" />
            <asp:Parameter Name="category_ID" Type="Int32" />
            <asp:Parameter Name="category_name" Type="String" />
            <asp:Parameter Name="description" Type="String" />
            <asp:Parameter Name="inventory_num" Type="Int32" />
            <asp:Parameter Name="cost" Type="Double" />
            <asp:Parameter Name="price" Type="Decimal" />
            <asp:Parameter Name="weight" Type="Double" />
            <asp:Parameter Name="image" Type="String" />
            <asp:Parameter Name="thumbnail" Type="String" />
        </InsertParameters>
        <UpdateParameters>
            <asp:Parameter Name="name" Type="String" />
            <asp:Parameter Name="category_ID" Type="Int32" />
            <asp:Parameter Name="category_name" Type="String" />
            <asp:Parameter Name="description" Type="String" />
            <asp:Parameter Name="inventory_num" Type="Int32" />
            <asp:Parameter Name="cost" Type="Double" />
            <asp:Parameter Name="price" Type="Decimal" />
            <asp:Parameter Name="weight" Type="Double" />
            <asp:Parameter Name="image" Type="String" />
            <asp:Parameter Name="thumbnail" Type="String" />
            <asp:Parameter Name="product_ID" Type="Int32" />
        </UpdateParameters>
    </asp:SqlDataSource>
    <p>
    </p>
    <asp:GridView ID="GridView1" runat="server" AllowPaging="True" AllowSorting="True" BackColor="White" 
        BorderColor="#E7E7FF" BorderStyle="None" BorderWidth="1px" CellPadding="3" DataSourceID="SqlDataSource1" 
        GridLines="Horizontal" OnSelectedIndexChanged="GridView1_SelectedIndexChanged" AutoGenerateColumns="False" DataKeyNames="product_ID">
        <AlternatingRowStyle BackColor="#F7F7F7" />
        <Columns>
            <asp:BoundField HeaderText="Product ID" DataField="product_ID" ReadOnly="True" SortExpression="product_ID" >
            <ControlStyle Font-Bold="True" />
            </asp:BoundField>
            <asp:BoundField HeaderText="Product Name" DataField="name" SortExpression="name" >
            <ControlStyle Font-Names="Corbel" />
            </asp:BoundField>
            <asp:BoundField HeaderText="Category ID" DataField="category_ID" SortExpression="category_ID" />
            <asp:BoundField HeaderText="Category Name" DataField="category_name" SortExpression="category_name" />
            <asp:BoundField HeaderText="Description" DataField="description" SortExpression="description" />
            <asp:BoundField HeaderText="Inventory" DataField="inventory_num" SortExpression="inventory_num" />
            <asp:BoundField HeaderText="Cost" DataField="cost" SortExpression="cost" />
            <asp:BoundField HeaderText="Price" DataField="price" SortExpression="price" />
            <asp:BoundField HeaderText="Weight" DataField="weight" SortExpression="weight" />
            <asp:BoundField HeaderText="Image" DataField="image" SortExpression="image" />
            <asp:BoundField DataField="thumbnail" HeaderText="Thumbnail" SortExpression="thumbnail" />
        </Columns>
        <FooterStyle BackColor="#B5C7DE" ForeColor="#4A3C8C" />
        <HeaderStyle BackColor="#4A3C8C" Font-Bold="True" ForeColor="#F7F7F7" />
        <PagerStyle BackColor="#E7E7FF" ForeColor="#4A3C8C" HorizontalAlign="Right" />
        <RowStyle BackColor="#E7E7FF" ForeColor="#4A3C8C" />
        <SelectedRowStyle BackColor="#738A9C" Font-Bold="True" ForeColor="#F7F7F7" />
        <SortedAscendingCellStyle BackColor="#F4F4FD" />
        <SortedAscendingHeaderStyle BackColor="#5A4C9D" />
        <SortedDescendingCellStyle BackColor="#D8D8F0" />
        <SortedDescendingHeaderStyle BackColor="#3E3277" />
    </asp:GridView>
</asp:Content>
