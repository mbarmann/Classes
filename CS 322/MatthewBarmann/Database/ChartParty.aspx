<%@ Page Title="" Language="C#" MasterPageFile="~/Site.Master" AutoEventWireup="true" CodeBehind="ChartParty.aspx.cs" Inherits="MatthewBarmann.Pages.ChartParty" %>
<%@ Register assembly="System.Web.DataVisualization, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35" namespace="System.Web.UI.DataVisualization.Charting" tagprefix="asp" %>
<asp:Content ID="Content1" ContentPlaceHolderID="MainContent" runat="server">
    <div>
        <asp:Label runat="server" ID="Pricelbl" Text="Top 3 Prices in Dollars" />
    </div>
    <div>
        <asp:Chart ID="Chart2" runat="server" DataSourceID="Barmann">
        <Series>
            <asp:Series Name="Series1" XValueMember="name" YValueMembers="price">
            </asp:Series>
        </Series>
        <ChartAreas>
            <asp:ChartArea Name="ChartArea1">
            </asp:ChartArea>
        </ChartAreas>
    </asp:Chart>
    </div>
    <div>
        <asp:Label runat="server" ID="Profitlbl" Text="Top 3 Profits in Dollars" />
    </div>
    <div>
        <asp:SqlDataSource ID="Barmann" runat="server" ConnectionString="<%$ ConnectionStrings:Barmann %>" SelectCommand="TopThreePrices" SelectCommandType="StoredProcedure"></asp:SqlDataSource>
    <asp:Chart ID="ProfitChart" runat="server">
        <Series>
            <asp:Series Name="Series1">
            </asp:Series>
        </Series>
        <ChartAreas>
            <asp:ChartArea Name="ChartArea1">
            </asp:ChartArea>
        </ChartAreas>
    </asp:Chart>
    </div>
</asp:Content>
