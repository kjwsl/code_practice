use std::path::Path;
use std::sync::Arc;
use tokio::io::{AsyncReadExt, AsyncWriteExt};
use tokio::net::{UnixListener, UnixStream};
use tokio::sync::Mutex;

#[tokio::main]
async fn main() -> std::io::Result<()> {
    let socket_path = "/tmp/rust_uds.sock";

    if Path::new(socket_path).exists() {
        std::fs::remove_file(socket_path)?;
    }

    let listener = UnixListener::bind(socket_path)?;
    println!("Listening on: {:?}", listener.local_addr()?);

    let connections = Arc::new(Mutex::new(Vec::<UnixStream>::new()));

    loop {
        let (stream, addr) = listener.accept().await?;
        println!("New client connected: {:?}", addr);

        let connections = Arc::clone(&connections);
        tokio::spawn(async move {
            if let Err(e) = handle_client(stream).await {
                eprintln!("Error handling client: {}", e);
            }
        });
    }

    Ok(())
}

async fn handle_client(mut stream: UnixStream) -> std::io::Result<()> {
    let mut buf = [0; 1024];

    let bytes_read = stream.read(&mut buf).await?;
    if bytes_read == 0 {
        return Ok(());
    }

    let received = String::from_utf8_lossy(&buf[..bytes_read]);
    println!("Received: {}", received);

    stream.write_all(b"Echo: ").await?;
    stream.write_all(&buf[..bytes_read]).await?;
    println!("Sent response");

    Ok(())
}
