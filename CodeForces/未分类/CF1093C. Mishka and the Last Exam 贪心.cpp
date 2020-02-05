void dfs() {
  int u, step;

  while (top >= 0) {
    step       = st[top].step;
    u          = st[top].val;
    path[step] = u;
    top--;

    if (step == m) break;

    for (int& j = head[u]; j; j = edge[j].next) {
      node t = edge[j];

      if (!vis[j]) {
        vis[j]    = vis[j ^ 1] = true;
        st[++top] = Stack(t.to, ++step);
        break;
      }
    }
  }
}
